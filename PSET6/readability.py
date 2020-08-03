from cs50 import get_string
import math
L = 0
S = 0
letters = 0
char_total = 0
words_ = 0 
sen_ = 0 
counter = 0
special1 = 0
special2 = 0
space = 0
sentence = 0
# Get the user's input
input = get_string("Enter sentence:")
counter = len(input)
# Get the amount of letters in input
for i in range(counter):
    if ord(input[i]) >= 32 and ord(input[i]) <= 64:
        special1 += 1
        if ord(input[i]) >= 94 and ord(input[i]) <= 96:
            special2 += 1            
letters = counter - special1 - special2 
# Get the amount of words in input
for i in range(counter):
    if ord(input[i]) == 32:
        space += 1
words_ = space + 1
# Get the amount of sentences in input
for i in range(counter):
    if ord(input[i]) == 46 or ord(input[i]) == 33 or ord(input[i]) == 63:
        sentence += 1
sen_ = sentence
L = letters / words_ * 100
S = sen_ / words_ * 100
# Get the index of the user's input
index = round((0.0588 * L) - (0.296 * S) - 15.8)
# Print various grades depending on the user's input
if index < 0:
    print("Before Grade 1") 
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {int(index)}")     