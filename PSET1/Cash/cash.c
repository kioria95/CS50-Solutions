#include<cs50.h>
#include<stdio.h>
#include<math.h>


int main(void)
{
    float change;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    
    int quart_count = 0, dime_count = 0, nickel_count = 0, total_count = 0;
    int quart_mod = 0, dime_mod = 0, nickel_mod = 0;
    
    do
    {
        change = get_float("What's the change?");
    }
    
    
    while (change < 0);
    
    
    
    int output = round(change * 100);
    
    //Change output to quarters
    
    quart_count = output / quarter;
    
    quart_mod = output % quarter;
    
    
    //Print the output in terms of quarters
    
    printf("In quarters: %i \n", quart_count);
    
    //If there the quarters are not enough, add dimes
        
    if (quart_mod != 0)
    {
        
        dime_count = quart_mod / dime;
        
        dime_mod = quart_mod % dime;
        
        printf("In dimes of: %i \n", dime_count);
        
    }
    //If there the dimes are not enough, add nickels
        
    if (dime_mod != 0)
    {
        nickel_count = dime_mod / nickel;
        
        nickel_mod = dime_mod % nickel;
        
        printf("In nickel of: %i \n", nickel_count);
    }
    
    //If there the nickels are not enough, add pennies
    
    if (nickel_mod != 0)
    {
        
        printf("In pennies of: %i \n", nickel_mod);
    }
    
    
    
    //Getting the total count of all the coins in terms of quarters, dimes, nickels and pennies
     
    total_count = (quart_count + dime_count + nickel_count + nickel_mod);
        
    printf("%i \n", total_count);
    
    
    
    
    
}