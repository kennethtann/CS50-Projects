#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int avg = round((red + green + blue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}




// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int newRed = round(0.393 * red + 0.769 * green + 0.189 * blue);

            if (newRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = newRed;
            }




            int newGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);

            if (newGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = newGreen;
            }



            int newBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            if (newBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = newBlue;
            }

        }
    }
    return;
}




// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;
        }
    }
    return;
}






// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     for( int i = 0; i < height  ; i++)
    {
        for( int j = 0; j < width ; j++)
        {
            int sumR = 0, sumG = 0, sumB = 0, count = 0;

            int indexs[9][2] = {
                {i-1, j-1}, {i-1, j}, {i-1, j+1},
                {i, j-1}, {i, j}, {i, j+1},
                {i+1, j-1}, {i+1, j}, {i+1, j+1}
            };

            for( int k = 0; k < 9; k++)
            {

                if( indexs[k][0] >= 0 && indexs[k][0] <= height && indexs[k][1] >= 0 && indexs[k][1] <= width)
                {

                    RGBTRIPLE currentImg = image[indexs[k][0]][indexs[k][1]];

                    sumR += currentImg.rgbtRed;
                    sumB += currentImg.rgbtBlue;
                    sumG += currentImg.rgbtGreen;

                    count++;
                }
            }
            
            image[i][j].rgbtRed = round(sumR/ (float) count);
            image[i][j].rgbtBlue = round(sumB/ (float) count);
            image[i][j].rgbtGreen = round(sumG/ (float) count);
        }
    }
    return;
}
