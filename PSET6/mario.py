from cs50 import get_int
answer = 0
while answer < 1 or answer > 8:
    answer = get_int("Enter Height:")
# if the answer keyed in is more than 2, do the following
if answer > 2:
    for i in range(0, answer):
        for j in range(7, i, -1):
            print(" ", end="")
        for k in range(-1, i):
            print("#", end="")
        print("\n", end="")     
# Else if the answer is 1, print one hash        
elif answer == 1:
    print("#")
# If the answer is exactly 2, print as per format required    
elif answer == 2:
    for l in range(1, 3):
        for s in range(2, l, -1):
            print(" ", end="")
        for m in range(0, l):
            print("#", end="")
        print("\n", end="")