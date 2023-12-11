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

# Configure CS50 Library to use SQLite database. Use db.execute to execute a SQL statement
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

    # Empty list to append stocks later after lookup
    stocks = []

    user_id = session["user_id"]

    # Get user's stocks
    user_stocks = db.execute("SELECT * FROM stocks WHERE user_id = ? GROUP BY symbol", user_id)


    # Calculate total value of each stock
    for stock in user_stocks:
        lookup_stock = lookup(stock["symbol"])
        stock["name"] = lookup_stock["name"]
        stock["price"] = lookup_stock["price"]
        stock["symbol"] = lookup_stock["symbol"]
        stock["total"] = stock["shares"] * stock["price"]

        stocks.append(stock)

    # Cash balance
    user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    if not user_cash:
        return apology("User not found", 403)
    elif len(user_cash) > 1:
        return apology("Multiple users found with the same ID")
    else:
        # [0] first element of the list as the user logged in is the only one and ["cash"] is the key
        user_cash = user_cash[0]["cash"]

    # Total portfolio value
    total_value = user_cash + sum(stock["total"] for stock in stocks)

    return render_template("index.html", stocks=stocks, user_cash=user_cash, total_value=total_value)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # Create a new table (stocks) in finance.db
    db.execute("""
        CREATE TABLE IF NOT EXISTS stocks (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            symbol TEXT NOT NULL,
            shares INTEGER NOT NULL,
            price NUMERIC NOT NULL,
            total NUMERIC NOT NULL,
            FOREIGN KEY (user_id) REFERENCES users(id)
        )
    """)

    if request.method=="POST":
        symbol = request.form.get("symbol").upper()
        # Lookup func will give us all the info the user has
        look_symbol = lookup(symbol)
        if look_symbol is None:
            return apology("Invalid entry", 400)

        shares = request.form.get("shares")
        # Ensure the shares input is a positive integer
        if not shares.isdigit() or int(shares) <= 0:
            return apology("Shares cannot be negative", 400)

        # Current price
        stock_price = look_symbol["price"]

        total_price = int(shares) * stock_price

        # Lookup how much cash user has
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        if not user_cash:
            return apology("User not found", 403)
        elif len(user_cash) > 1:
            return apology("Multiple users found with the same ID")
        else:
            # [0] first element of the list as the user logged in is the only one and ["cash"] is the key
            user_cash = user_cash[0]["cash"]

        if (user_cash) < (total_price):
            return apology("Not enough cash to buy stock", 400)
        else:
            # Check if the user already owns shares of this stock
            existing_shares = db.execute("SELECT shares FROM stocks WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)

            if existing_shares:
                # User already owns shares, update the existing entry
                updated_shares = existing_shares[0]["shares"] + int(shares)
                db.execute("UPDATE stocks SET shares = ? WHERE user_id = ? AND symbol = ?", updated_shares, session["user_id"], symbol)
            else:
                # User doesn't own shares, insert a new entry
                db.execute("INSERT INTO stocks (user_id, symbol, shares, price) VALUES (?,?,?,?)", session["user_id"], symbol, shares, stock_price)

            # Deduct the cost of the purchased stock from the user's cash
            new_cash = user_cash - total_price

            # Update cash in db
            db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session["user_id"])

            # Return to the main page
            return redirect("/")

            # Deduct the cost of the purchased stock from the user's cash
            # new_cash = user_cash - total_price

            # # Update cash in db
            # db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session["user_id"])

            # # Update stocks table
            # db.execute("""
            # INSERT INTO stocks (user_id, symbol, shares, price)
            # VALUES (?,?,?,?)""", session["user_id"], symbol, shares, stock_price)

            # # Return to the main page
            # return redirect("/")

    else:
        return render_template("buy.html")


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

    if request.method == "POST":
        symbol = request.form.get("symbol")
        look_symbol = lookup(symbol)
        return render_template("quoted.html", symbol=look_symbol)

    else:
        return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Forget any userid
    session.clear()

    # If user is submitting something
    if request.method == "POST":

        username = request.form.get("username")
        password = request.form.get("password")
        verifypassword = request.form.get("verifypassword")
        # Ensure username was submitted
        if not username:
            return apology("must provide username", 403)

        # Ensure username is not taken already by querying database
        result = db.execute("SELECT * FROM users WHERE username = ?", username)
        # Checks if result returned any rows
        if result:
            return apology("Username already taken", 403)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 403)

        elif not verifypassword:
            return apology("must verify password", 403)

        # When passwords don't match
        elif password != verifypassword:
            return apology("password does not match", 403)

        # If all good, add to database (users table)
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?,?)",
            username,
            generate_password_hash(password),
        )

        # Retrieve the userid after inserting into the database
        user_id = db.execute("SELECT id FROM users WHERE username = ?", username)

        # Once registeration is done, keep track of the user
        session["user_id"] = user_id[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # For get request
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        shares = request.form.get("shares")
        

    else:
        return render_template("sell.html")
