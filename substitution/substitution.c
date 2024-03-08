#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validation(string s);

int main(int argc, string argv[])
{

}

bool validation(string s)
{
    // check if there is only digits in the command-line argument
    for (int i = 0, lenght = strlen(s); i < lenght; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

