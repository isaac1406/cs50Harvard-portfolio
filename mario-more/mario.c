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
    for(int k = 0; k < spaces; k++)
    {
        printf(" ");
    }
    // print bricks
    for(int i = 0; i < lenght; i++)
    {
        printf("#");
    }
    printf("  ");
    for(int l = 0; l < lenght; l++)
    {
        printf("#");
    }
    printf("\n");
}
