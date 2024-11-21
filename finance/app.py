import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == 'POST':
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        # check if symbol was submitted
        if not symbol:
            return apology("must provide symbol")
        # check if shares was submitted
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("must provide a positive integer number of shares")

        quote = lookup



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
    # form submitted via POST
    if request.method == "POST":
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        # check if symbol is valid
        if not quote:
            return apology("invalid symbol", 400)
        return render_template("quote.html", quote=quote)
    # form submitted via GET
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # forget any user id
    session.clear()

    # form submitted via POST
    if request.method == "POST":

        # check if username was submitted
        if not request.form.get("username"):
            return apology("Username required", 400)
        # check if password was submitted
        elif not request.form.get("password"):
            return apology("Password required", 400)
        # check if confirmation was submitted
        elif not request.form.get("password"):
            return apology("Username required", 400)
        # check if password and confirmation match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match")
        # query databse for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        # check if username already exists
        if len(rows) != 0:
            return apology("Username already exists")

        # insert new user into database
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)",
                   request.form.get("username"), generate_password_hash(request.form.get("password")))
        # query database for new user
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        # remenber the user that logged in
        session["user_id"] = rows[0][id]

        # redirect to home page
        return redirect("/")

    # form submitted via GET
    else:
        return render_template("registration.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
