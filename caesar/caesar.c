#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string s)
{
    for (int i = 0, lenght = strlen(s); i < lenght; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
}
