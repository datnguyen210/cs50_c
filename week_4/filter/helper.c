#include "helper.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy to a new image.
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Replace each rgbtriple by the average value of pixels forming a 3x3 box around it.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;
            for (int di = -1; di <= 1; di++)
            {
                for(int dj = -1; dj <= 1; dj++)
                {
                    int newI = i + di;
                    int newJ = j + dj;
                    if(newI >=0 & newI < height & newJ >=0 & newJ < width)
                    {
                        redSum += copy[newI][newJ].rgbtRed;
                        greenSum += copy[newI][newJ].rgbtGreen;
                        blueSum += copy[newI][newJ].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round((float)redSum / count);
            image[i][j].rgbtBlue = round((float)blueSum / count);
            image[i][j].rgbtGreen = round((float)greenSum / count);
        }
    }
    printf("GOES HERE");
    return;
}
