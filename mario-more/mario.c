#include <cs50.h>
#include <stdio.h>

void pyramids(int spaces, int lenght);

int main(void)
{
    // prompt the user for the height of the two pyramids
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height < 1 || height > 8);
    int space = height;
    // print the adjacent pyramids of that height
    for(int j = 1; j <= height; j++)
    {
        space--;
        pyramids(space, j);
    }
}

void pyramids(int spaces, int lenght)
{
    // print spaces
    for(int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    // print first pyramid
    for(int i = 0; i < lenght; i++)
    {
        printf("#");
    }
    printf("  ");
    // print second pyramid
    for(int i = 0; i < lenght; i++)
    {
        printf("#");
    }
    printf("\n");
}
