// Implements a dictionary's functionality

#include <stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *hashtable[1000];

unsigned int num_words = 0;
bool loaded_ = false;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char word_check[strlen(word)];
    strcpy(word_check, word);
    
   for (int i = 0; word_check[i] != '\0'; i++)
   {
      word_check[i] = tolower(word_check[i]);
   }
   
   int index = hash(word_check);
   if (hashtable[index] != NULL)
   {
       for (node *pointer_ = hashtable[index]; pointer_  != NULL; pointer_  = pointer_ ->next)
       {
          if (strcmp(pointer_ -> word, word_check) == 0)
          {
            return true;
          }
       }
   }
   return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    int p;
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            p = word[i] - 'a' + 1;
        }
        else
        {
            p = 27;
        }
        
        hash = ((hash << 3) + p) % 1000;
    }
   return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
      return false;
    }
    
    for (int i = 0; i < 1000; i++)
    {
        hashtable[i] = NULL;
    }
    
    char word[LENGTH + 1];
    node *pointer_new;
    
    while (fscanf(infile, "%s", word) != EOF)
    {
        num_words++;
        do
        {
            pointer_new = malloc(sizeof(node));
            if(pointer_new == NULL)
            {
                free(pointer_new);
            }
        }
        
        while (pointer_new == NULL);
        
        strcpy(pointer_new->word,word);
        int index = hash(word);
       
        pointer_new->next = hashtable[index];
        hashtable[index] =pointer_new;
    
    }
    
    fclose(infile);
    loaded_ = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!loaded_)
    {
      return 0;
    }
    return num_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
   if (!loaded_)
   {
        return false;
   }
  
  for (int i = 0; i < 1000; i++)
  {
    node* point_ = hashtable[i];
      
    while (point_ != NULL)
   {
        node* predptr = point_;
        point_ = point_->next;
        free(predptr);
   }
  }
  return true;
}
