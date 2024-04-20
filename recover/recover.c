#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2){
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Open the memory card
    uint8_t buffer[512];

    int count = 0;
    char *name = malloc(8);

    // While there's still data left to read from the memory card
    while(fread(buffer, 1, 512, card) == 512){
        sprintf(name, "%03i.jpg", count);
        FILE *img = fopen(name, "w");
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[3] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            count++;
            fwrite(buffer, 1, 512, img);
        }
        else{
            fwrite(buffer, 1, 512, img);
        }
        fclose(img);
    }
    free(name);
    fclose(card);
}
