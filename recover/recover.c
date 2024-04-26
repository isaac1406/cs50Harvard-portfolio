#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // check if the file exists
    if (card == NULL)
        printf("Could not open %s", argv[1]);

    // initialize variables
    bool found = false;
    uint8_t buffer[512];
    int count = 0;
    char name[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while(fread(buffer, 1, 512, card) == 512)
    {
        // check JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            found = true;
        // found the signature
        if (found == true)
        {
            // check if it's the first JPEG
            if (count != 0)
            {
                fclose(img);
            }
            // write into the new file
            sprintf(name, "%03i.jpg", count);
            img = fopen(name, "w");
            fwrite(buffer, 1, 512, img);
            found = false;
            count++;
        }
        // If it isn't the first JPEG
        else if (count != 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    // close open files
    fclose(card);
    fclose(img);
    return 0;
}
