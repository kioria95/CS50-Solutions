#include<cs50.h>
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int upper = 65;
int lower = 97;
int n = 0;
int key;
int correct = 0;
 
void encrypt();

int main(int argc, string argv[])
{


    if (argc == 2)
    {
        
        int b = strlen(argv[1]);
         
        for (int l = 0; l < b; l++)
        {
            if (isdigit(argv[1][l]))
            {
                correct++;
        
            }
    
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
    
    
        
        }
    
        if (correct >= 1)
        {
            key = atoi(argv[1]);
            encrypt(); 
        } 
        
    }
    
   

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}
    
void encrypt()
{
       
//Print success when conditions are met

    printf("Success\n");
        
    string input = get_string("Enter words:");
        
    n = strlen(input);
        
    printf("ciphertext: ");
                
        
    for (int i = 0; i < n; i++)
    {
//Check for uppercase character and add key

        if (isupper(input[i]))
        {
                
            char ans1 = ((input[i] - upper + key) % 26) + upper;
            printf("%c", ans1);
        }
//Check for lowercase character and add key  

        else if (islower(input[i]))
        {
            char ans1 = ((input[i] - lower + key) % 26) + lower;
            printf("%c", ans1);
        }
//If other character, print without rotating  

        else
        {
            printf("%c", input[i]);
        }
        
    }
        
    printf("\n");
        
}
        
