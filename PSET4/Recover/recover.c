#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;
bool is_new(BYTE buffer[]);

int main(int argc, char *argv[])
{
//Check if the arguments are more than one
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
  
//Open the file specified and read contents

    FILE *infile = fopen(argv[1], "r");
    
//If no such file is found, print error message     
    if (infile == NULL)
    {
        printf("File not found \n");
        return 1;
    }
  
//Declare the buffer size  
    BYTE buffer[512];
  
    int file_index = 0;
    bool first_ = false;
    FILE *outfile;
  
    while (fread(buffer, 8, 1, infile))
    {
        if (is_new(buffer))
        {
          
            if (!first_)
            {
                first_ = true;
            }
            else
            {
                fclose(outfile);
            }
            char filename[8];
//Rename the files found            
            
            sprintf(filename, "%03i.jpg", file_index++);
            outfile = fopen(filename, "w");
          
            if (outfile == NULL)
            {
                return 1;
            }
          
            fwrite(buffer, 8, 1, outfile);
        }
      
        else if (first_)
        {
            fwrite(buffer, 8, 1, outfile);
        }
    }
 
//Close both the output and card.raw files  
    fclose(outfile);
    fclose(infile);
}

bool is_new(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

}
