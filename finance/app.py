import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Create table for stocks owned
    db.execute(
        """
        CREATE TABLE if not exists stocks(
        user_id INTEGER NOT NULL,
        symbol TEXT NOT NULL,
        share_qty INTEGER NOT NULL)
        """
    )

    # get sum of transactions
    stocks = db.execute(
        "SELECT symbol, share_qty FROM stocks WHERE user_id = :id GROUP BY symbol HAVING share_qty > 0",
        id=session["user_id"],
    )
    # if no
    if not stocks:
        return apology("No stocks owned.", code="404")

    # get balance
    cash = db.execute(
        "SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"]
    )[0]["cash"]

    # total values
    portfolio_total = cash

    # iterate over stocks
    for stock in stocks:
        # Look up quote for symbol.
        quote = lookup(stock["symbol"])

        # the current price of each stock,
        stock["price"] = quote["price"]

        # and the total value of each holding (i.e., shares times price).
        stock["total"] = stock["price"] * stock["share_qty"]

        # Also display the user’s current cash balance along with a grand total (i.e., stocks’ total value plus cash).
        portfolio_total += stock["total"]

        # format into usd
        stock["price"] = usd(stock["price"])
        stock["total"] = usd(stock["total"])

    # render index template
    return render_template(
        "index.html",
        cash=usd(cash),
        portfolio_total=usd(portfolio_total),
        stocks=stocks,
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # render buy template
    if request.method == "GET":
        return render_template("buy.html")

    # user submitted data
    elif request.method == "POST":
        # check if symbol and shares is valid
        symbol = request.form.get("symbol").upper()
        if symbol == "":
            return apology("Missing Symbol")

        # check if number of shares is valid
        shares = request.form.get("shares")
        if shares == "":
            return apology("Missing Shares")

        # lookup symbol
        symbol_quote = lookup(symbol)

        # check if symbol valid
        if symbol_quote == None:
            return apology("Invalid Symbol")

        # price of share
        price = symbol_quote["price"]

        # total cost of stock
        total_cost = price * int(shares)

        # check how much cash the user currently has in users.
        cash = db.execute(
            "SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"]
        )

        # check if user has enough money for the purchase
        balance = int(cash[0]["cash"]) - total_cost
        if balance < 0:
            return apology("Not enough cash for this purchase.")

        # Create table for transactions
        db.execute(
            """
            CREATE TABLE if not exists transactions(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            type TEXT NOT NULL,
            user_id INTEGER NOT NULL,
            symbol TEXT NOT NULL,
            share_qty INTEGER NOT NULL,
            price INTEGER NOT NULL,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (user_id) REFERENCES users(id))
            """
        )

        # update user balance
        db.execute(
            "UPDATE users SET cash = :balance WHERE id = :id",
            balance=balance,
            id=session["user_id"],
        )

        # insert data into transactions table
        db.execute(
            "INSERT INTO transactions (type, user_id, symbol, share_qty, price) VALUES (:type, :user_id, :symbol, :share_qty, :price)",
            type="buy",
            user_id=session["user_id"],
            symbol=symbol,
            share_qty=shares,
            price=price,
        )

        # check if user already owns the same stocks
        records = db.execute(
            "SELECT * FROM stocks WHERE user_id = :user_id AND symbol = :symbol",
            user_id=session["user_id"],
            symbol=symbol,
        )
        # insert
        if records:
            # update number of stock
            db.execute(
                "UPDATE stocks SET share_qty = share_qty + :shares WHERE user_id = :user_id AND symbol = :symbol",
                shares=shares,
                user_id=session["user_id"],
                symbol=symbol,
            )
        else:
            # insert new stock
            db.execute(
                """
                INSERT INTO stocks (user_id, symbol, share_qty) VALUES (:user_id, :symbol, :share_qty)
                """,
                user_id=session["user_id"],
                symbol=symbol,
                share_qty=shares,
            )

        # flash message
        flash(f"You bought {shares} stocks of {symbol} for ${total_cost}!")
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # get user transactions
    transactions = db.execute(
        "SELECT * FROM transactions WHERE user_id = :user_id", user_id=session["user_id"]
    )
    # render template
    return render_template("history.html", transactions=transactions)



@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # input stock symbol
    if request.method == "GET":
        return render_template("quote.html")

    # user submitted data
    elif request.method == "POST":
        # check if symbol is empty
        symbol = request.form.get("symbol")
        if symbol == "":
            return apology("Missing Symbol")

        # lookup stock price
        symbol_quote = lookup(symbol)
        # check if symbol valid
        if symbol_quote == None:
            return apology("Invalid Symbol")

        # show stock price
        else:
            return render_template(
                "quoted.html",
                name=symbol_quote["name"],
                price=symbol_quote["price"],
                symbol=symbol_quote["symbol"],
            )


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")

    elif request.method == "POST":
        # get username and password
        username = request.form.get("username")
        password = request.form.get("password")
        # Check if username is not blank
        if username == "":
            return apology("Please Input a Username")

        # Check if password matches
        if password != request.form.get("confirmation"):
            return apology("Password does not match")

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Check if username exists
        if len(rows) != 0:
            return apology("Username already exists", 403)
        # If username does not exist
        else:
            # Remember registrant
            db.execute(
                "INSERT INTO users (username, hash) VALUES(?, ?)",
                username,
                generate_password_hash(password),
            )

    # flash message
    flash(f"Registration Succesful!")
    return redirect("/index.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # get user stocks and owned shares
    stocks = db.execute(
        "SELECT symbol, share_qty FROM stocks WHERE user_id = :user_id GROUP BY symbol HAVING share_qty > 0",
        user_id=session["user_id"],
    )
    # list of symbols owned
    symbols = []

    # render sell page
    if request.method == "GET":
        # get stocks owned by user
        for stock in stocks:
            symbols.append(stock["symbol"].upper())

        # check if user has available stocks to sell
        if not stocks:
            return apology("No stocks to sell.", code=404)

        # render template if user has available stocks to sell
        else:
            return render_template("/sell.html", symbols=symbols)

    elif request.method == "POST":
        # get number of shares from user input
        no_shares = request.form.get("shares")

        # check if number of shares from user input is not empty
        if no_shares == "":
            return apology("Stock must not be empty!")

        # check if number of shares from user input is not a positive integer
        no_shares = int(no_shares)

        if no_shares < 0:
            return apology("Stock must be greater than 0!")

        # get symbol from user input
        symbol = request.form.get("symbol")

        # check if the user does not own that many shares of the stock.
        # iterate over all owned stocks
        for stock in stocks:
            # if user inputted symbol matches current item
            if stock["symbol"] == symbol:
                # if user inputted stock number is greater than owned stocks
                if int(no_shares) > int(stock["share_qty"]):
                    # error message
                    return apology("Not enough Stocks!")
                else:
                    # update stock count
                    db.execute(
                        "UPDATE stocks SET share_qty = share_qty - :no_shares WHERE user_id = :user_id AND symbol = :symbol",
                        no_shares=no_shares,
                        user_id=session["user_id"],
                        symbol=symbol,
                    )
                    # get current stock price quote
                    symbol_quote = lookup(symbol)

                    # total stock price
                    price = symbol_quote["price"] * no_shares

                    # add selling price to total user cash
                    db.execute(
                        "UPDATE users SET cash = cash + :price WHERE id = :id",
                        price=price,
                        id=session["user_id"],
                    )

                    # insert sold stocks to transactions table
                    db.execute(
                        "INSERT INTO transactions (type, user_id, symbol, share_qty, price) VALUES (:type, :user_id, :symbol, :share_qty, :price)",
                        type="sell",
                        user_id=session["user_id"],
                        symbol=symbol,
                        share_qty=no_shares,
                        price=price,
                    )

                    # flash message
                    flash(f"You sold {no_shares} stocks of {symbol} for ${price}!")
                    return redirect("/")
