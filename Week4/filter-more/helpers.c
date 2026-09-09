#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;
    float average;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen);
            average = round(average / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = (.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) +
                       (.189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            sepiaRed = round(sepiaRed);
            sepiaGreen = (.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) +
                         (.168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = (.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) +
                        (.131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            sepiaBlue = round(sepiaBlue);
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Go through every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            float count = 0;

            // Check all neighbors, including itself
            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    // Make sure the neighbor is inside the image
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        red += copy[x][y].rgbtRed;
                        green += copy[x][y].rgbtGreen;
                        blue += copy[x][y].rgbtBlue;

                        count++;
                    }
                }
            }

            // Calculate average
            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = round(blue / count);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    float Gx_red = 0;
    float Gy_red = 0;
    float G_red;

    float Gx_blue = 0;
    float Gy_blue = 0;
    float G_blue;

    float Gx_green = 0;
    float Gy_green = 0;
    float G_green;

    int k;
    int m;

    // Create a copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Go through every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check all neighbors, including itself
            k = 0;

            Gx_red = 0;
            Gy_red = 0;

            Gx_blue = 0;
            Gy_blue = 0;

            Gx_green = 0;
            Gy_green = 0;

            for (int x = i - 1; x <= i + 1; x++, k++)
            {
                m = 0;
                for (int y = j - 1; y <= j + 1; y++, m++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        Gx_red += copy[x][y].rgbtRed * Gx[k][m];
                        Gy_red += copy[x][y].rgbtRed * Gy[k][m];

                        Gx_blue += copy[x][y].rgbtBlue * Gx[k][m];
                        Gy_blue += copy[x][y].rgbtBlue * Gy[k][m];

                        Gx_green += copy[x][y].rgbtGreen * Gx[k][m];
                        Gy_green += copy[x][y].rgbtGreen * Gy[k][m];
                    }
                }
            }

            G_red = round(sqrt((Gx_red * Gx_red) + (Gy_red * Gy_red)));
            G_blue = round(sqrt((Gx_blue * Gx_blue) + (Gy_blue * Gy_blue)));
            G_green = round(sqrt((Gx_green * Gx_green) + (Gy_green * Gy_green)));

            if (G_red > 255)
            {
                G_red = 255;
            }

            if (G_blue > 255)
            {
                G_blue = 255;
            }

            if (G_green > 255)
            {
                G_green = 255;
            }

            image[i][j].rgbtRed = G_red;
            image[i][j].rgbtBlue = G_blue;
            image[i][j].rgbtGreen = G_green;
        }
    }

    return;
}
