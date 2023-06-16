# Hall of Prophecy

import csv
from cs50 import SQL

# Open database
db = SQL("sqlite:///./prophecy/roster.db")

# Open CSV file
with open("./prophecy/students.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)
    for row in reader:
        id = row["id"]
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        db.execute("INSERT INTO student (id, student_name) VALUES(?, ?)", id, name)
        db.execute("INSERT INTO houses (id, house) VALUES(?, ?)", id, house)
        db.execute("INSERT INTO heads (id, head) VALUES(?, ?)", id, head)


