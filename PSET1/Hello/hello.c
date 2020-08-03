#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt the user to enter their name
    string answer = get_string("What is your name? \n");
    
    //Print out the result
    printf("Hello %s \n", answer);
}