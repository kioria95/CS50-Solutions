from csv import reader, DictReader
from sys import argv, exit
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
# Read the DNA from file
with open(argv[2]) as dnafile:
    reader_ = reader(dnafile)
    for row in reader_:
        dnalist = row
# Store the DNA sequence
dna = dnalist[0]
# create a dictionary where we will store the sequences we intend to count
sequences = {}
# extract the sequences from the database into a list
with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break
# Copy the list in a dictionary where the genes are the keys
for item in dnaSequences:
    sequences[item] = 1
# Go trough the dna sequence, when it finds repetitions of the values from sequence dictionary it counts them
for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        while temp > 0:
            temp -= 1
            continue
# When  DNA segment matches matches with key and there is  repetition, start counting
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l
# Compares value of previous longest sequence and if longer, it's overriden
            if temp > tempMax:
                tempMax = temp
# Store longest DNA sequences in the dictionary using its respective key
    sequences[key] += tempMax
# Open file and scan the database
with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
# Compares the sequences
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")