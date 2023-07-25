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

        if not password:
            return apology("Please Input a Password")

        # Check if password matches
        if password != request.form.get("confirmation"):
            return apology("Password does not match")

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Check if username exists
        if len(rows) != 0:
            return apology("Username already exists", 400)
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
    return render_template("/index.html")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # create database for terms list
    db.execute(
        """
        CREATE TABLE IF NOT EXISTS terms (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        japanese TEXT,
        english TEXT,
        topic_id INTEGER,
        FOREIGN KEY(topic_id)
        REFERENCES topic(id))
        """
    )

    # create database for programming languages list
    db.execute(
        """
        CREATE TABLE IF NOT EXISTS topic (
        id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
        name TEXT UNIQUE)
        """
    )

    # render index template
    return render_template("index.html")


# add new terms to the dictionary
@app.route("/add_term", methods=["GET", "POST"])
@login_required
def add_term():
    """Ask for user input"""
    if request.method == "GET":
        return render_template("add_term.html")

    elif request.method == "POST":
        # get terms from user input
        japanese = request.form.get("japanese")
        english = request.form.get("english")
        topic = request.form.get("topic")

        # check that all fields have input
        if not japanese or not english or not topic:
            # flash message
            flash("Sorry, please provide information for all fields!")
            return render_template("/add_term.html")

        # check if user input is not None(not defined)
        if japanese is None or english is None or topic is None:
            # flash message
            flash("Sorry, please provide information for all fields!")
            return render_template("/add_term.html")

        # upper case topic
        topic = topic.upper()

        # check database if topic already exists and get topic_id
        topic_id = None
        try:
            topic_id = db.execute(
                """
                SELECT id FROM topic WHERE name = :topic
                """,
                topic=topic
            )
        except Exception as e:
                # flash message
                flash(f"Failed to insert new topic { topic },: { e }!")


        # if topic does not exist
        inserted_rows = 0
        if not topic_id:
            # insert new topic into database
            try:
                inserted_rows = db.execute(
                    """
                    INSERT INTO topic (name)
                    VALUES (:topic)
                    """,
                    topic=topic
                )
            except Exception as e:
                # flash message
                flash(f"Sorry, term registration to database was not successful, { e }")
                return render_template("/add_term.html")

        # check if insert was success
        if not inserted_rows:
            # flash message
            flash("Sorry, term registration to database was not successful.")
            return render_template("/add_term.html")

        # get topic_id
        try:
            topic_id = db.execute(
                """
                SELECT id FROM topic
                WHERE name = :topic
                """,
                topic=topic
            )

        except Exception as e:
            # flash message
            flash(f"Sorry, term registration to database was not successful, { e }")
            return render_template("/add_term.html")

        # check if there was an id found
        if not topic_id:
            # flash message
            flash("Sorry, failed to retrieve Topic ID!")
            return render_template("/add_term.html")

        # add term to database
        try:
            inserted_term = 0
            inserted_term = db.execute(
                """
                INSERT INTO terms (japanese, english, topic_id)
                VALUES (:japanese, :english, :topic_id)
                """,
                japanese=japanese,
                english=english,
                topic_id=topic_id[0]["id"]
            )
        except Exception as e:
            # flash message
            flash(f"Sorry, term registration to database was not successful. { e }")
            return render_template("/add_term.html")

        # check if adding of term was success
        if inserted_term == 0:
            # flash message
            flash(f"Sorry, term registration was not successful!")
            return render_template("/add_term.html")
        elif inserted_term != 0:
            # flash message
            flash(f"Term registration successful!")
            # render add_term template
            return render_template("add_term.html")


# display terms by their topics
@app.route("/list", methods=["GET", "POST"])
@login_required
def list():
    """Ask for user input"""
    if request.method == "GET":
        return render_template("list.html")

    elif request.method == "POST":
        # flash message
        flash(f"todo")
        return render_template("list.html")


