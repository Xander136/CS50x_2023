import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required

# Configure application
app = Flask(__name__)

# Custom filter
# app.jinja_env.filters["usd"] = usd

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
    """Shows cards that of the most common Programming Language and Topics"""
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
    """Add new terms to the database"""
    # Ask for user input
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
                topic=topic,
            )
        except Exception as e:
            # flash message
            flash(f"Failed to insert new topic { topic },: { e }!")

        # if topic does not exist

        if not topic_id:
            # insert new topic into database
            inserted_rows = 0
            try:
                inserted_rows = db.execute(
                    """
                    INSERT INTO topic (name)
                    VALUES (:topic)
                    """,
                    topic=topic,
                )
                # check if insert was success
                if not inserted_rows:
                    # flash message
                    flash("Sorry, term registration to database was not successful.")
                    return render_template("/add_term.html")

            except Exception as e:
                # flash message
                flash(f"Sorry, term registration to database was not successful, { e }")
                return render_template("/add_term.html")

        # get topic_id
        try:
            topic_id = db.execute(
                """
                SELECT id FROM topic
                WHERE name = :topic
                """,
                topic=topic,
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
                topic_id=topic_id[0]["id"],
            )
        except Exception as e:
            # flash message
            flash(f"Sorry, term registration to database was not successful. { e }")
            return render_template("/add_term.html")

        # check if adding of term was success
        if inserted_term == 0:
            # flash message
            flash(
                f"Sorry, term registration was not successful!, 263 if inserted_term == 0:"
            )
            return render_template("/add_term.html")
        elif inserted_term != 0:
            # flash message
            flash(f"Term registration successful!")
            # render add_term template
            return render_template("add_term.html")


# display all registered terms
@app.route("/list", methods=["GET", "POST"])
@login_required
def list():
    """show list of all the terms"""
    if request.method == "GET":
        # SELECT all items from terms table and join related items from topic
        try:
            terms = 0
            terms = db.execute(
                """
                SELECT
                    trm.id,
                    trm.japanese,
                    trm.english,
                    tpc.name
                FROM
                    terms as trm
                INNER JOIN topic AS tpc
                    ON trm.topic_id = tpc.id
                ORDER BY
                    english
                """
            )
            # check if there were selected terms
            if not terms:
                # flash message
                flash(
                    f"Something went wrong. There were no records selected. However, You can add new terms for that topic."
                )
                return render_template("/add_term.html")

        except Exception as e:
            # flash message
            flash(f"Something went wrong. { e }")
            return render_template("/add_term.html")

        return render_template("list.html", terms=terms)

    elif request.method == "POST":
        # try to get topic
        try:
            topic = request.form.get("button").upper()

            if not topic:
                # flash message
                flash(f"Something went wrong. No topic data found.")
                return render_template("/index.html")

            terms = 0
            terms = db.execute(
                """
                SELECT
                    trm.id,
                    trm.japanese,
                    trm.english,
                    tpc.name
                FROM
                    terms as trm
                INNER JOIN topic AS tpc
                    ON trm.topic_id = tpc.id
                WHERE tpc.name LIKE :topic
                ORDER BY
                    english
                """,
                topic=topic,
            )
            # check if there were selected terms
            if not terms:
                # flash message
                flash(
                    f"Something went wrong. There were no records selected. However, You can add new terms for that topic."
                )
                return render_template("/add_term.html")

            return render_template("list.html", terms=terms)

        except Exception as e:
            # flash message
            flash(f"Something went wrong. { e }")
            return render_template("/index.html")


@app.route("/search", methods=["GET", "POST"])
def search():
    """Search for a Japanese or English Term or a Topic"""
    if request.method == "GET":
        # Redirect user to search
        return render_template("/search.html")

    elif request.method == "POST":
        # try to get search
        try:
            topic = request.form.get("search")

            if not topic:
                # flash message
                flash(f"Something went wrong. No search data found.")
                return render_template("/search.html")

            terms = 0
            terms = db.execute(
                """
                SELECT
                    trm.id,
                    trm.japanese,
                    trm.english,
                    tpc.name
                FROM
                    terms as trm
                INNER JOIN topic AS tpc
                    ON trm.topic_id = tpc.id
                WHERE
                    tpc.name LIKE :topic
                OR
                    trm.japanese LIKE :topic
                OR
                    trm.english LIKE :topic
                ORDER BY
                    english
                """,
                topic=topic,
            )
            # check if there were selected terms
            if not terms:
                # flash message
                flash(
                    f"Something went wrong. There were no records found. However, You can add new terms for that topic."
                )
                return render_template("/add_term.html")

            # flash message for how many search hits were found
            hits = 0
            for items in terms:
                hits += 1
            flash(f"Found { hits } items.")

            # render list template
            return render_template("list.html", terms=terms)

        except Exception as e:
            # flash message
            flash(f"Something went wrong. { e }")
            return render_template("/index.html")

# edit a registered term
@app.route("/update", methods=["GET", "POST"])
@login_required
def update():
    if request.method == "GET":
        try:
            # try to get term id
            id = request.form.get("button")

            # get term information
            term = 0
            term = db.execute(
                """
                SELECT
                    trm.id,
                    trm.japanese,
                    trm.english,
                    tpc.name
                FROM
                    terms as trm
                INNER JOIN topic AS tpc
                    ON trm.topic_id = tpc.id
                WHERE
                    trm.id = :id
                ORDER BY
                    english
                """,
                id=id
            )

            if term == 0:
                # flash message
                flash(f"Something went wrong. Term was not found.")
                return render_template("/list.html")

            elif term:
                # render update template
                return render_template("/update.html", term=term)


        except Exception as e:
            # flash message
            flash(f"Something went wrong. { e }")
            return render_template("/list.html")

    elif request.method == "POST":
        if 


# delete a registered term
@app.route("/delete", methods=["GET", "POST"])
@login_required
def delete():
    return apology("todo")

