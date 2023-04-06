#include "helpers.h"
#include <math.h>

int blur_value(int x, int y, int height, int width, RGBTRIPLE copy[height][width], int color);

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
// blur_value(x, y, height, width, copy, BLUE);

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

    // variable for colors
    int BLUE = 0;
    int GREEN = 1;
    int RED = 2;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            image[x][y].rgbtBlue = blur_value(x, y, height, width, copy[height][width], BLUE);
            image[x][y].rgbtGreen = blur_value(x, y, height, width, copy[height][width], GREEN);
            image[x][y].rgbtRed = blur_value(x, y, height, width, copy[height][width], RED);
        }
    }
    return;
}

int blur_value(int x, int y, int height, int width, RGBTRIPLE copy[height][width], int color)
{
    width -= 1;
    height -= 1;
    int sum;
    int cube_count;

    for (int row = x - 1; row < 3; row++)
    {
        for (int column = y - 1; column < 3; column++)
        {
            if (row < 0 || column < 0 || row > width || column > height)
            {
                continue;
            }
            else
            {
                // blue
                if (color == 0)
                {
                    sum += copy[row][column].rgbtBlue;
                    cube_count++;
                }
                // green
                else if (color == 1)
                {
                    sum += copy[row][column].rgbtGreen;
                    cube_count++;
                }
                // red
                else if (color == 2)
                {
                    sum += copy[row][column].rgbtRed;
                    cube_count++;
                }
            }
        }
    }
    int average = round(sum / (float) cube_count);
    return average;
}

