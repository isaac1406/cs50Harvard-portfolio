#include <cs50.h>
#include <stdio.h>

void row(int spaces, int lenght);

int main(void)
{
    // prompt the user for the pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height < 1);
    int space = height;
    // print a pyramid of the prompted height
    for(int j = 1; j <= height; j++)
    {
        space--;
        row(space, j);
    }
}

void row(int spaces, int lenght)
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
    printf("\n");
}
