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
    // check if there are 26 letters
    if (strlen(s) != 26)
    {
        return false;
    }

    for (int i = 0, lenght = strlen(s); i < lenght; i++)
    {
        // check if all chars are letters
        if (isalpha(s[i]) == 0)
        {
            return false;
        }

        // check if there isn't any repeated letters
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}

