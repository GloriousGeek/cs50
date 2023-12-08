import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Global variable
PEOPLE = {}

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        db.execute("SELECT * FROM birthdays")

        # Fetching data from index.html
        name = request.args.get('name')
        month = request.args.get('month')
        day = request.args.get('day')



        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        # User is getting the website

        # Query for all birthdays
        entries = db.execute("SELECT * FROM birthdays").fetchall()

        # Check entries in index.html
        return render_template("index.html", birthdays = entries)



