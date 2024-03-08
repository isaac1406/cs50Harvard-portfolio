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
        printf("Key must contain 26 different letters.\n");
        return 1;
    }

    // ask for plaintext
    string plain = get_string("Plaintext:  ");

    // new ciphered text
    string cipher = substitute(plain, argv[1]);
    printf("ciphertext: %s\n", cipher);
}

string substitute(string plain, string key)
{
    // uppercase and lowercase alphabet
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";

    // loop to pick each letter of the plaintext
    for (int i = 0, lenght = strlen(plain); i < lenght; i++)
    {
        // check if it's an alphabetical char
        if (isalpha(plain[i]))
        {
            // check if it's in uppercase
            if (isupper(plain[i]))
            {
                // guarantee all the letters in the key are in uppercase too
                for (int j = 0, num = strlen(key); j < num; j++)
                {
                    key[j] = toupper(key[j]);
                }
                // go through the alphabet letters
                for (int k = 0, num = strlen(upper); k < num; k++)
                {
                    // see what letter it is
                    if (plain[i] == upper[k])
                    {
                        // change it for the respective one in the key
                        plain[i] = key[k];
                        break;
                    }
                }
            }

            // check if it's in lowercase
            else
            {
                // guarantee all the letters in the key are in lowercase too
                for (int j = 0, num = strlen(key); j < num; j++)
                {
                    key[j] = tolower(key[j]);
                }
                // go through the alphabet letters
                for (int k = 0, num = strlen(lower); k < num; k++)
                {
                    // see what letter it is
                    if (plain[i] == lower[k])
                    {
                        // change it for the respective one in the key
                        plain[i] = key[k];
                        break;
                    }
                }
            }
        }
    }
    // return the already ciphered text
    return plain;
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

