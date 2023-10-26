#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int rmain, gmain, bmain;
    float gout;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rmain = image[i][j].rgbtRed;
            gmain = image[i][j].rgbtGreen;
            bmain = image[i][j].rgbtBlue;

            gout = round((rmain + gmain + bmain) / 3.0);

            image[i][j].rgbtRed = gout;
            image[i][j].rgbtGreen = gout;
            image[i][j].rgbtBlue = gout;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    float sepiaRed, sepiaGreen, sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE rowplace[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rowplace[j] = image[i][j];
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = rowplace[width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = rowplace[width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = rowplace[width - j - 1].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            float rsum = 0, gsum = 0, bsum = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (!(i + k < 0 || i + k >= height || j + l < 0 || j + l >= width))
                    {
                        rsum += copy[i + k][j + l].rgbtRed;
                        gsum += copy[i + k][j + l].rgbtGreen;
                        bsum += copy[i + k][j + l].rgbtBlue;
                        counter++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            image[i][j].rgbtRed = (int)round(rsum / counter);
            image[i][j].rgbtGreen = (int)round(gsum / counter);
            image[i][j].rgbtBlue = (int)round(bsum / counter);
        }
    }
    return;
}
