#include "helpers.h"
#include <math.h>
#include<cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
//To convert to grayscale, one has to take the RGB values and get the average of them
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

//If output value is higher than 255, make it 255. Else, let output value remain
int max(int output)
{
    if (output > 255)
    {
        return 255;
    }
    
    else
    {
        return output;
    }
    
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
//Using values provided by Harvard to get sepia            
            RGBTRIPLE pixel = image[i][j];
            image[i][j].rgbtRed = max(round(0.393 * pixel.rgbtRed  + 0.769 * pixel.rgbtGreen + 0.189 * pixel.rgbtBlue));
            image[i][j].rgbtGreen = max(round(0.349 * pixel.rgbtRed  + 0.686 * pixel.rgbtGreen + 0.168 * pixel.rgbtBlue));
            image[i][j].rgbtBlue = max(round(0.272 * pixel.rgbtRed  + 0.534 * pixel.rgbtGreen + 0.131 * pixel.rgbtBlue));
        }
    }
}  

//Declaring a function that swaps values 
void flip(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp_value = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp_value;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
//flip the images
        for (int j = 0; j < width / 2; j++)
        {
            flip(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

bool pixel_alright(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int red_val = 0, blue_val = 0, green_val = 0;
    int pixels_ok = 0;
    
    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            int new_i = i + k;
            int new_j = j + l;
            if (pixel_alright(new_i, new_j, height, width))
            {
                pixels_ok++;
                red_val += image[new_i][new_j].rgbtRed;
                green_val += image[new_i][new_j].rgbtGreen;
                blue_val += image[new_i][new_j].rgbtBlue;
             
            }
        }
    }
    
    RGBTRIPLE blurred;
//Round up various values of red,green and blue    
    blurred.rgbtRed = round((float) red_val / pixels_ok);
    blurred.rgbtGreen = round((float) green_val / pixels_ok);
    blurred.rgbtBlue = round((float) blue_val / pixels_ok);
//Return the values
    return blurred;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = get_blurred_pixel(i, j, height, width, image);
        }
    }
//Put the new values         
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    
}

