#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // get each pixel
    // height
    for (int i = 0; i < height; i++)
    {
        // width
        for (int j = 0; j < width; j++)
        {
            // calculate the average pixel value
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Set each color value to the average value
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // get each pixel
    // height
    for (int i = 0; i < height; i++)
    {
        // width
        for (int j = 0; j < width; j++)
        {
            // Set each color value to variables
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int originalRed = image[i][j].rgbtRed;

            // calculate the sepia values
            int sepiaRed = round((.189 * image[i][j].rgbtBlue) + (.769 * image[i][j].rgbtGreen) + (.393 * image[i][j].rgbtRed));
            int sepiaRed = round((.393 * originalRed + .769 * originalGreen + .189 * originalBlue) * 1.0);
            int sepiaGreen = round((.349 * originalRed + .686 * originalGreen + .168 * originalBlue) * 1.0);
            int sepiaBlue = round((.272 * originalRed + .534 * originalGreen + .131 * originalBlue) * 1.0);

            // Set each color value to the average value
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur imagefi
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

