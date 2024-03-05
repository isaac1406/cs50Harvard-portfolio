#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index

    // Print the grade level
}

string upper(string text)
{
    for (int x = 0, lenght = strlen(text); x < lenght; x++)
    {
        string new += toupper(text[x]);
    }
    return text;
}
int count_letters(string text)
{
    // Return the number of letters in text
    for (int i = 0, lenght = strlen(text); i < lenght; i++)
    {
        if (a <= text[i] <= z || )
    }
}

int count_words(string text)
{
    // Return the number of words in text
}

int count_sentences(string text)
{
    // Return the number of sentences in text
}
