#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            float average = (red + green + blue) / 3.0;
            average = round(average);

            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take original red, green, and blue
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            // Compute sepia values
            float sepiaRed = .393 * red + .769 * green + .189 * blue;
            float sepiaGreen = .349 * red + .686 * green + .168 * blue;
            float sepiaBlue = .272 * red + .534 * green + .131 * blue;
            // round float numbers to the nearest int
            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);
            // Ensure the resulting value is no larger than 255
            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            // Update pixel with sepia values
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
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixels
            RGBTRIPLE temporary = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temporary;
        }
    }
    return;
}

int get_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width], char color)
{
    int counter = 0, sum = 0;
    // loop through only the surroundings
    for (int row = i - 1; row <= (i + 1); row++)
    {
        for (int collumn = j - 1; collumn <= (j + 1); collumn++)
        {
            // check if it's out of boundaries
            if (row < 0 || row >= height || collumn < 0 || collumn >= width)
                continue;
            // apply the sum for the color called
            if (color == 'r')
                sum += image[row][collumn].rgbtRed;
            else if (color == 'g')
                sum += image[row][collumn].rgbtGreen;
            else
                sum += image[row][collumn].rgbtBlue;
            // count the how many pixels there are in the proximity
            counter++;
        }
    }
    // return the average of the surroundings to blur that pixel
    return round(sum / counter);
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image [i][j].rgbtRed = get_blur(i, j, height, width, copy, 'r');
            image [i][j].rgbtGreen = get_blur(i, j, height, width, copy, 'g');
            image [i][j].rgbtBlue = get_blur(i, j, height, width, copy, 'b');
        }
    }
    return;
}
