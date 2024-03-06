#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int formula(int numlet, int numwor, int numsen);
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
    int grade = formula(letters, words, sentences);

    // Print the grade level
}

// formula to be used
int formula(int numlet, int numwor, int numsen)
{
    float L = (numlet * 100.0) / (numwor);
    float S = (numsen * 100.0) / (numwor);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

// Return the number of letters in text
int count_letters(string text)
{
    int counterl = 0;
    for (int i = 0, lenght = strlen(text); i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            counterl++;
        }
    }
    return counterl;
}

// Return the number of words in text
int count_words(string text)
{
    int counterw = 1;
    for (int i = 1, lenght = strlen(text); i < lenght; i++)
    {
        if (text[i - 1] != ' ' && text[i] == ' ' && text[i + 1] != ' ')
        {
            counterw++;
        }
    }
    return counterw;
}

// Return the number of sentences in text
int count_sentences(string text)
{
    int counters = 0, lenght = strlen(text), i = 0;
    for (i = 0; i < lenght; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            counters++;
        }
    }
    return counters;
}
