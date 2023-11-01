#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check for the black pixel. All should be zero
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00)
            {
                // Turn black pixel to Green. FF = 255 (maximum value)
                image[i][j].rgbtGreen == 0xFF;
            }
        }
    }
}
