#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of the three to ensure same brightness
            BYTE avg_gray = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/(3.0);

            // Set all RGB to gray
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg_gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterating through height and width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Rounding to nearest integer
            // BYTE struct can cause a problem if the value goes above 255 as it starts counting from 0 and onwards.
            double sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            double sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            double sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Cap values at 255 if they exceed it
            // Set all RGB pixel to Sepia
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = (BYTE)sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = (BYTE)sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = (BYTE)sepiaBlue;
            }

            // // Set all RGB pixel to Sepia
            // image[i][j].rgbtRed = BYTE (sepiaRed);
            // image[i][j].rgbtGreen = BYTE (sepiaGreen);
            // image[i][j].rgbtBlue = BYTE (sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterating through each row
    // Every row, swap pixels to the horizontal (width) opp side
    for (int i = 0; i < height; i++)
    {
        // Iterate through half of the columns - width (left to right)
        for (int j = 0; j < width/2; j++)
        {
            // Temperory variable to store original color info of current pixel at (i,j)
            RGBTRIPLE temp = image[i][j];

            // Swap current pixel with that of opp side (right)
            image[i][j] = image[i][width - 1 - j];

            // Swap opp side pixel color (right) with that of temp variable original pixel (left)
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterating through height/rows
    for (int i = 0; i < height; i++)
    {
        // Iterate through columns (x-coordinate)
        for (int j = 0; j < width; j++)
        {
            // Loop over pixel and 3x3 neighbor centered around (x,y)
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; k <= 1; k++)
                {
                    if
                }
            }
            RGBTRIPLE new_value =
            image[i][j] =
        }
    }
    return;
}
