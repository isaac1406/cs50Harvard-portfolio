#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validation(string s);
string substitute(string plain, string key);

int main(int argc, string argv[])
{
    // check if there's only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // validate the key
    if (validation(argv[1]) == false)
    {
        printf("Key must contain 26 letters.");
        return 1;
    }

    // ask for plaintext
    string plain = get_string("Plaintext: ");
}

string substitute(string plain, string key)
{
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0, lenght = strlen(plain); i < lenght; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                for (int j = 0, num = strlen(key); j < num; j++)
                {
                    toupper(key[j]);
                }

                for (int k = 0, num = strlen(upper); k < num; k++)
                {
                    if (plain[i] == upper[k])
                    {
                        plain[i] = key[k];
                        break;
                    }
                }
            }

            else
            {
                for (int j = 0, num = strlen(key); j < num; j++)
                {
                    tolower(key[j]);
                }

                for (int k = 0, num = strlen(lower); k < num; k++)
                {
                    if (plain[i] == lower[k])
                    {
                        plain[i] = key[k];
                        break;
                    }
                }
            }
        }
    }
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

