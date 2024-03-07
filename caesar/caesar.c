#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    printf("ciphertext: ");

    // rotate the letters to ciphered
    for (int i = 0, lenght = strlen(plain); i < lenght; i++)
    {
        plain[i] = rotate(plain[i], key);
        printf("%c", plain[i]);
    }
    printf("\n");
}

char rotate(char c, int n)
{
    char new = c;

    // check if the char is a letter
    if (isalpha(c))
    {
        // rotate
        new += n;

        // check if a uppercase got out of the letter boundaries of ASCII
        if (isupper(c))
        {
            c -= 65;
            new = (c + n) % 26;
            new += 65;
        }

        // check if a lowercase case got out of the letter boundaries of ASCII
        else
        {
            c -= 97;
            new = (c + n) % 26;
            new += 97;
        }
    }
    // return the ciphered char
    return new;
}

bool only_digits(string s)
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
