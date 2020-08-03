from cs50 import get_float
change = 0
quarter = 25
dime = 10
nickel = 5
quart_count = 0
dime_count = 0 
nickel_count = 0
total_count = 0
quart_mod = 0
dime_mod = 0
nickel_mod = 0
change = get_float("Change? ")
while change < 0:
    change = get_float("Change? ")
output = round(change * 100)
# Change output to quarters   
quart_count = output / quarter  
quart_mod = output % quarter     
# Print the output in terms of quarters   
print(f"In quarters:{int(quart_count)}")
# Print the output including dimes
if quart_mod != 0:
    dime_count = quart_mod / dime
    dime_mod = quart_mod % dime    
    print(f"In dimes of:{int(dime_count)}")  
# Print the output including nickels
if dime_mod != 0:
    nickel_count = dime_mod / nickel
    nickel_mod = dime_mod % nickel
    print(f"In nickel of:{int(nickel_count)}")           
# If there the nickels are not enough, add pennies
if nickel_mod != 0:
    print(f"In pennies of:{int(nickel_mod)}")   
# Getting the total count of all the coins in terms     
total_count = int(quart_count) + int(dime_count) + int(nickel_count) + int(nickel_mod)       
print(f"{total_count}")