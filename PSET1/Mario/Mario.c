#include<cs50.h>
#include<stdio.h>

int main(void)
{
  
    int answer;
    
    do
    {
        answer = get_int("Height:");
    }
    
    //While condition to test if answer is between the range of 1 and 8
    while (answer < 1 || answer > 8);
    
    
    //If answer is 8, do the following
    if (answer == 8)
    {
    
        for (int i = 0; i < answer; i++)
        {
            for (int s = 7; s > i; s--)
            {
                printf(" ");
             
            }
       
            for (int k = -1; k < i; k++)
            {
                printf("#"); 
            }
       
            printf("\n");
 
        }
    
    }
    
    
    //If answer is 2, do the following
    else if (answer == 2)
    {
        for (int l = 1; l <= answer; l++)
        {
            
            for (int s = 2; s > l; s--)
            {
                printf(" ");
             
            } 
            for (int m = 0; m < l; m++)
            {
                printf("#");  
            }
            printf("\n");
        }
    }
    
    
    //If answer is 1, do the following
    else if (answer == 1)
    {
        printf("#\n"); 
    }
    
    
    //Otherwise, do the following
    else 
    {
        for (int l = 1; l <= answer; l++)
        {
       
            for (int m = 0; m < l; m++)
            {
                printf("#");  
            }
            
            printf("\n");
        }
    }

}



