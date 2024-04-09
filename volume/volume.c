// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // set the buffer with the header size
    uint8_t header[HEADER_SIZE];
    // read the header from input
    fread(header, HEADER_SIZE, 1, input);
    // write that same header in output
    fwrite(header, HEADER_SIZE, 1, output);

    // set buffer
    int16_t buffer;
    // loop to read all the samples from input
    while(fread(&buffer, sizeof(int16_t), 1, input)){
        // update the samples
        buffer *= factor;
        // copy the updated samples into output
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
    return 0;
}
