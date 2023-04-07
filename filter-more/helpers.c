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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // get each pixel
    // height
    int half_width = width / 2;
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

//Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create array for copy of image
    RGBTRIPLE copy[height][width];

    // get each pixel
    // height
    for (int h = 0; h < height; h++)
    {
        // width
        for (int w = 0; w < width; w++)
        {
            // copy colors of image
            copy[h][w] = image[h][w];
        }
    }

    // select every pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // set color values
            int blue = 0;
            int green = 0;
            int red = 0;
            int pixel_count = 0;

            // loop over 3x3 grid around the current pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // check for out of range pixels
                    if ((x + w) < 0 || (x + w) > (width - 1) || (y + h) < 0 || (y + h) > (height - 1))
                    {
                        continue;
                    }
                    else
                    {
                        // get color values from valid pixels
                        blue += copy[(y + h)][(x + w)].rgbtBlue;
                        green += copy[(y + h)][(x + w)].rgbtGreen;
                        red += copy[(y + h)][(x + w)].rgbtRed;
                        pixel_count++;
                    }
                }
            }
            //get average of color values
            int ave_blue = round(blue / (float) pixel_count);
            int ave_green = round(green / (float) pixel_count);
            int ave_red = round(red / (float) pixel_count);

            // store changed values to original image
            image[h][w].rgbtBlue = ave_blue;
            image[h][w].rgbtGreen = ave_green;
            image[h][w].rgbtRed = ave_red;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create array for copy of image
    RGBTRIPLE copy[height][width];

    // get each pixel
    // height
    for (int h = 0; h < height; h++)
    {
        // width
        for (int w = 0; w < width; w++)
        {
            // copy colors of image
            copy[h][w] = image[h][w];
        }
    }

    // select every pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // set color values
            int Gx_blue = 0;
            int Gx_green = 0;
            int Gx_red = 0;
            int Gx_pixel_count = 0;
            int Gx = 0;
            int Gy = 0;
            int Gx_multiplier[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};

            // loop over 3x3 grid around the current pixel
            // Gx
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // check for out of range pixels
                    if ((x + w) < 0 || (x + w) > (width - 1) || (y + h) < 0 || (y + h) > (height - 1))
                    {
                        Gx_pixel_count++;
                    }
                    else
                    {
                        // get color values from valid pixels
                        Gx_blue += Gx_multiplier[Gx_pixel_count] * (copy[(y + h)][(x + w)].rgbtBlue);
                        Gx_green += Gx_multiplier[Gx_pixel_count] * copy[(y + h)][(x + w)].rgbtGreen;
                        Gx_red += Gx_multiplier[Gx_pixel_count] * copy[(y + h)][(x + w)].rgbtRed;
                        Gx_pixel_count++;
                    }
                }
            }

            // set color values
            int Gy_blue = 0;
            int Gy_green = 0;
            int Gy_red = 0;
            int Gy_pixel_count = 0;
            int Gx = 0;
            int Gy = 0;
            int Gy_multiplier[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

            // loop over 3x3 grid around the current pixel
            // Gy
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // check for out of range pixels
                    if ((x + w) < 0 || (x + w) > (width - 1) || (y + h) < 0 || (y + h) > (height - 1))
                    {
                        Gy_pixel_count++;
                    }
                    else
                    {
                        // get color values from valid pixels
                        Gy_blue += Gy_multiplier[Gy_pixel_count] * (copy[(y + h)][(x + w)].rgbtBlue);
                        Gy_green += Gy_multiplier[Gy_pixel_count] * (copy[(y + h)][(x + w)].rgbtGreen);
                        Gy_red += Gy_multiplier[Gy_pixel_count] * (copy[(y + h)][(x + w)].rgbtRed);
                        Gy_pixel_count++;
                    }
                }
            }

            //get Gx^2 + Gy^2 color values
            int ave_blue = round(blue / (float) pixel_count);
            int ave_green = round(green / (float) pixel_count);
            int ave_red = round(red / (float) pixel_count);

            // store changed values to original image
            image[h][w].rgbtBlue = ave_blue;
            image[h][w].rgbtGreen = ave_green;
            image[h][w].rgbtRed = ave_red;
        }
    }
    return;
}
