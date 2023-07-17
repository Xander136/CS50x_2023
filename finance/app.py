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
    transactions = db.execute(
        "SELECT * FROM transactions WHERE user_id = :id", id=session["user_id"]
    )
    transactions[]
    return render_template("index.html")


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
        symbol = request.form.get("symbol")
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
        cash = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])

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
            "UPDATE users SET cash = :balance WHERE id = :id", balance=balance, id=session["user_id"]
        )

        # insert data
        db.execute(
            "INSERT INTO transactions (type, user_id, symbol, share_qty, price) VALUES (:type, :user_id, :symbol, :share_qty, :price)",
            type="buy",
            user_id=session["user_id"],
            symbol=symbol,
            share_qty=shares,
            price=price
        )
        flash(f"You bought {shares} stocks of {symbol} for {total_cost}!")
        return redirect("/")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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

    # Confirm registration
    return apology("registered")
    # return render_template("/index")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
