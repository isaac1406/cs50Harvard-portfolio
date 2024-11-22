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
    # get user's stocks and shares
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0",
                        session["user_id"])
    # get user's cash balance
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    # initialize variables for total values
    total_value = cash
    grand_total = cash

    # Iterate over stocks and add price and total value
    for stock in stocks:
        quote = lookup(stock["symbol"])
        stock["name"] = quote["name"]
        stock["price"] = quote["price"]
        stock["value"] = stock["price"] * stock["total_shares"]
        total_value += stock["value"]
        grand_total += stock["value"]

    return render_template("index.html", stocks=stocks, cash=cash, total_value=total_value, grand_total=grand_total)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == 'POST':
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Check if symbol was submitted
        if not symbol:
            return apology("must provide symbol")

        # Check if shares was submitted
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("must provide a positive integer number of shares")

        # Check if the symbol can be found
        quote = lookup(symbol)
        if quote is None:
            return apology("Symbol not found")

        price = quote["price"]
        total_cost = int(shares) * price

        # Corrected SQL query with placeholder
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        # Check if there's enough cash
        if cash < total_cost:
            return apology("not sufficient cash")

        # Update users table
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, session["user_id"])

        # Add the purchase to the history table
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (:user_id, :symbol, :shares, :price)",
                   user_id=session["user_id"], symbol=symbol, shares=shares, price=price)

        flash(f"Bought {shares} shares of {symbol} for {usd(total_cost)}!")
        return redirect("/")

    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Query database for user's transactions
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = ? ORDER BY timestamp DESC", session["user_id"])

    # Render history page with transactions
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
    # get user's stocks
    stocks = db.execute("SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0", session["user_id"])

    # form submitted via POST
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Check if symbol was submitted
        if not symbol:
            return apology("must provide symbol")

        # Check if shares was submitted
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("must provide a positive integer number of shares")

        shares = int(shares)

        for stock in stocks:
            if stock["symbol"] == symbol:
                if stock["total_shares"] < shares:
                    return apology("not enough shares")
                # Get quote
                quote = lookup(symbol)
                if quote is None:
                    return apology("symbol not found")
                price = quote["price"]
                total_sale = shares * price

                # update users table
                db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total_sale, session["user_id"])

                # add the sale to history table
                db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", session["user_id"], symbol, -shares, price)

                flash(f"Sold {shares} shares of {symbol} for {usd(total_sale)}!")
                return redirect("/")

        return apology("symbol not found")

        # If the user visits the page
    else:
        return render_template("sell.html", stocks=stocks)

@app.route("/cash", methods=["GET", "POST"])
def cash():
    """Allow users to add additional cash to their account."""
    if request.method == "POST":
        # Get the amount of cash to add from the form
        additional_cash = request.form.get("cash")

        # Validate the input
        if not additional_cash or not additional_cash.isdigit() or int(additional_cash) <= 0:
            return apology("must provide a positive integer amount of cash")

        # Convert the input to an integer
        additional_cash = int(additional_cash)

        # Update the user's cash balance in the database
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", additional_cash, session["user_id"])

        # Flash a success message
        flash(f"Successfully added {usd(additional_cash)} to your account!")

        # Redirect to the homepage or another relevant page
        return redirect("/")

    else:
        # Render the cash.html template
        return render_template("cash.html")
