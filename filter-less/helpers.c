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

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImage[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            tmpImage[h][w] = image[h][w];
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // now we are on a current pixel of image[h][w]
            int reds = 0;
            int blues = 0;
            int greens = 0;
            int availablePixels = 0;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    // checks the boxes around the pixel by using [-1][-1], [-1][0], [-1][1], ... etc
                    // makes sure we don't go past width/height and 0
                    if ((h + i >= 0 && h + i < height) && (w + j >= 0 && w + j < width))
                    {
                        availablePixels++;
                        reds += tmpImage[h + i][w + j].rgbtRed;
                        greens +=  tmpImage[h + i][w + j].rgbtGreen;
                        blues +=  tmpImage[h + i][w + j].rgbtBlue;
                    }
                }
            }
            // set the current pixel we are on to the avg of the block
            image[h][w].rgbtRed = round(reds / (float) availablePixels);
            image[h][w].rgbtGreen = round(greens / (float)  availablePixels);
            image[h][w].rgbtBlue = round(blues / (float) availablePixels);
        }
    }
}


// blur_value(x, y, height, width, copy, BLUE);

// Blur image
// void blur(int height, int width, RGBTRIPLE image[height][width])
// {
//     // create array for copy of image
//     RGBTRIPLE copy[height][width];

//     // get each pixel
//     // height
//     for (int i = 0; i < height; i++)
//     {
//         // width
//         for (int j = 0; j < width; j++)
//         {
//             // copy colors of image
//             copy[i][j] = image[i][j];
//         }
//     }


//     // variable for sums of colors
//     int sum_blue = 0;
//     int sum_green = 0;
//     int sum_red = 0;

//     // height
//     for (int i = 0; i < height; i++)
//     {
//         // width
//         for (int j = 0; j < width; j++)
//         {
//             // variable for box count
//             int box_count = 0;

//             // get target row and increment for 3 times
//             for (int x = i - 1; x < (i + 2); x++)
//             {
//                 // get target column and increment 3 times
//                 for (int y = j - 1; y < (i + 2); y++)
//                 {
//                     // Skip if target box is outside of image width and height
//                     if (x < 0 || y < 0 || x > (width - 1) || y > (height - 1))
//                     {
//                         continue;
//                     }
//                     else
//                     {
//                         sum_blue += copy[x][y].rgbtBlue;
//                         sum_green += copy[x][y].rgbtGreen;
//                         sum_red += copy[x][y].rgbtRed;
//                         box_count++;
//                     }
//                 }
//             }
//             int average_blue = round(sum_blue / (float) box_count);
//             int average_green = round(sum_green / (float) box_count);
//             int average_red = round(sum_red / (float) box_count);

//             image[i][j].rgbtBlue = average_blue;
//             image[i][j].rgbtGreen = average_green;
//             image[i][j].rgbtRed = average_red;
//         }
//     }
//     return;
// }


