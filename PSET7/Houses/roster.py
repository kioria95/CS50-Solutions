from sys import argv, exit
from cs50 import SQL
# If arguments are less than required, print error message and exit
if len(argv) != 2:
    print("Usage: python roster.py [name of school]")
    exit(1)
db = SQL("sqlite:///students.db")
house_ = argv[1]
rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first",house_)
for i in rows:
    first, middle, last, birth = i["first"], i["middle"], i["last"], i["birth"]
    print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")