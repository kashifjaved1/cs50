#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            RGBTRIPLE PIXEL = image[i][j];
            int greyColor = round((PIXEL.rgbtRed + PIXEL.rgbtGreen + PIXEL.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = greyColor;
        }
    }
}

int check(int value){
    if(value > 255){
        return 255;
    }
    return value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            RGBTRIPLE PIXEL = image[i][j];
            int greyColor = round((PIXEL.rgbtRed + PIXEL.rgbtGreen + PIXEL.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = greyColor;

            int originalRed = PIXEL.rgbtRed;
            int originalGreen = PIXEL.rgbtGreen;
            int originalBlue = PIXEL.rgbtBlue;

            image[i][j].rgbtRed = check(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            image[i][j].rgbtGreen = check(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            image[i][j].rgbtBlue = check(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary image to be blurred
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_blue;
            int sum_green;
            int sum_red;
            float counter;
            sum_blue = sum_green = sum_red = counter = 0;

            //corner pixel on bottom right
            if (i >= 0 && j >= 0)
            {
                sum_red += temp[i][j].rgbtRed;
                sum_green += temp[i][j].rgbtGreen;
                sum_blue += temp[i][j].rgbtBlue;
                counter++;
            }
            //corner pixel on bottom left
            if (i >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i][j-1].rgbtRed;
                sum_green += temp[i][j-1].rgbtGreen;
                sum_blue += temp[i][j-1].rgbtBlue;
                counter++;
            }
            //corner pixel on top left
            if (i - 1 >= 0 && j >= 0)
            {
                sum_red += temp[i-1][j].rgbtRed;
                sum_green += temp[i-1][j].rgbtGreen;
                sum_blue += temp[i-1][j].rgbtBlue;
                counter++;
            }
            //corner pixel on top right
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i-1][j-1].rgbtRed;
                sum_green += temp[i-1][j-1].rgbtGreen;
                sum_blue += temp[i-1][j-1].rgbtBlue;
                counter++;
            }

            //pixels on bottom edge
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                sum_red += temp[i][j+1].rgbtRed;
                sum_green += temp[i][j+1].rgbtGreen;
                sum_blue += temp[i][j+1].rgbtBlue;
                counter++;
            }
            //pixels on top edge
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                sum_red += temp[i-1][j+1].rgbtRed;
                sum_green += temp[i-1][j+1].rgbtGreen;
                sum_blue += temp[i-1][j+1].rgbtBlue;
                counter++;
            }
            //pixels on left edge
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                sum_red += temp[i+1][j].rgbtRed;
                sum_green += temp[i+1][j].rgbtGreen;
                sum_blue += temp[i+1][j].rgbtBlue;
                counter++;
            }
            //pixels on right edge
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                sum_red += temp[i+1][j-1].rgbtRed;
                sum_green += temp[i+1][j-1].rgbtGreen;
                sum_blue += temp[i+1][j-1].rgbtBlue;
                counter++;
            }

            //middle pixels
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                sum_red += temp[i+1][j+1].rgbtRed;
                sum_green += temp[i+1][j+1].rgbtGreen;
                sum_blue += temp[i+1][j+1].rgbtBlue;
                counter++;
            }
            //find average colour value
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
}
