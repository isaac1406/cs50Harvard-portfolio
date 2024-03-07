#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // check if there's only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check if the command-line argument contains only digits
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert the string inputed into an int
    int key = atoi(argv[1]);

    // ask for plaintext
    string plain = get_string("Plaintext: ");

    // rotate the letters to
    for (int i = 0, lenght = strlen(plain); i < lenght; i++)
    {
        plain[i] = rotate(plain[i], key);
    }

}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        c += n;
    }
    return c;
}

bool only_digits(string s)
{
    for (int i = 0, lenght = strlen(s); i < lenght; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}
