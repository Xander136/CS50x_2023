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
            // calculate the sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
            int sepiaRed = round((.189 * image[i][j].rgbtBlue) + (.769 * image[i][j].rgbtGreen) + (.393 * image[i][j].rgbtRed));
            //sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue

            // calculate the sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
            int sepiaGreen = round((.168 * image[i][j].rgbtBlue) + (.686 * image[i][j].rgbtGreen) + (.349 * image[i][j].rgbtRed));

            // calculate the sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
            int sepiaBlue = round((.189 * image[i][j].rgbtBlue) + (.769 * image[i][j].rgbtGreen) + (.393 * image[i][j].rgbtRed));

            // Set each color value to the average value
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
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

