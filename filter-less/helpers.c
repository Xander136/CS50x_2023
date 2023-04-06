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
    // Max value of color
    int MAX_VALUE = 255;

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
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Set each color value to the computed value or max value
            if (sepiaBlue < MAX_VALUE)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = MAX_VALUE;
            }
            if (sepiaGreen < MAX_VALUE)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = MAX_VALUE;
            }
            if (sepiaRed < MAX_VALUE)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = MAX_VALUE;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // get each pixel
    // height
    int half_width = width/2;
    for (int i = 0; i < height; i++)
    {
        // width
        for (int j = 0; j < half_width; j++)
        {
            // swap colors
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create array for copy of image
    RGBTRIPLE copy[height][width];

    // get each pixel
    // height
    for (int i = 0; i < height; i++)
    {
        // width
        for (int j = 0; j < width; j++)
        {
            // copy colors of image
            copy[i][j] = image[i][j];
        }
    }

    // declare average color variables
    int ave_rgbtBlue;
    int ave_rgbtGreen;
    int ave_rgbtRed;
    // determine array item
    /*
    0 1 2 3 4
    1 2 3 4 5
    2 3 4 5 6
    1st h - 1 w - 1
    2nd h - 1 w - 0
    3rd h - 1 w + 1

    1st h - 0 w - 1
    2nd h - 0 w - 0
    3rd h - 0 w + 1

    1st h + 1 w - 1
    2nd h + 1 w - 0
    3rd h + 1 w + 1


     */
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            image[x][y].rgbtBlue = blur_value(x, y, height, width, copy[x][y].rgbtBlue);
            image[x][y].rgbtGreen = blur_value(copy[x][y].rgbtGreen);
            image[x][y].rgbtRed = blur_value(copy[x][y].rgbtRed);
        }
    }


    return;
}

int blur_value(int rgbtValue, int x, int y, int height, int width)
{
    width -= 1;
    height -= 1;
    for (int row = x - 1; row < 3; row++)
    {
        for (int column = y - 1; column < 3; column++)
        {
            if (row < width)

        }
    }

}
