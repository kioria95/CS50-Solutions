#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

void count_letters();
void count_words();
void count_sentences();


float L = 0, S = 0;
int special1 = 0, special2 = 0, letters = 0, space = 0;
int char_total = 0, words_ = 0, sen_ = 0, sentence = 0;
string input;


int main(void)
{
    //Get the user's input
 
    input = get_string("Enter sentence:");
    
    //Get the size of the input
    char_total = strlen(input);
    
 
    //Call various functions
    count_letters();
   
    count_words();
   
    count_sentences();
  

    L = ((float) letters / (float) words_) * 100;
     
    S = ((float) sen_ / (float) words_) * 100;
     
    float index =  round((0.0588 * L) - (0.296 * S) - 15.8);
    
    //IF conditions when the index is less than 0, greater than 16 and in between 1 and 16
   
    if (index < 0)
    {
       
        printf("Before Grade 1\n");
    }
   
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
   
    else 
    {
        printf("Grade %i\n", (int) index);
    }
     
}

void count_letters()
{
    
    for (int i = 0; i < char_total; i++)
    {
        if (input[i] >= 32 && input[i] <= 64)
         
        {
            special1++;
             
            if (input[i] >= 94 && input[i] <= 96)
            {
                special2++;
            }
            
        }
  
    }
   
    letters = char_total - special1 - special2 ;
   
}

void count_words()
{
  
    
    for (int i = 0; i < char_total; i++)
    {
        if (input[i] == 32)
         
        {
            space++;
            
        }
  
    }
    
    words_ = space + 1;
    
}

void count_sentences()
{
  
    for (int i = 0; i < char_total; i++)
    {
        if (input[i] == 46 || input[i] == 33 || input[i] == 63)
         
        {
            sentence++;
            
        }
  
    }
    
    sen_ = sentence;
    
}