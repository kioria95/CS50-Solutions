from cs50 import SQL
from sys import argv, exit
import csv
# Function to split the names into 3 as specified
def name_split(name_):
    names = name_.split()
    return names if len(names) >= 3 else [names[0], None, names[1]]
# If arguments are less than required, print error message and exit
if len(argv) != 2:
    print("Usage: python import.py [name of file]")
    exit(1)
db = SQL("sqlite:///students.db")
#Store the file name into a variable
path_ = argv[1]
with open(path_) as file_:
    reader = csv.DictReader(file_)
    for i in reader: 
        names = name_split(i["name"])
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", 
        names[0], names[1], names[2], i["house"], i["birth"])