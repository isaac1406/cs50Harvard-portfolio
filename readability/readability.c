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

int formula(int numlet, int numwor, int numsen)
{
    float L = (numlet * 100.0) / (numwor);
    float S = (numsen * 100.0) / (numwor);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) round(index);
    return grade;
}

int count_letters(string text)
{
    // Return the number of letters in text
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

int count_words(string text)
{
    // Return the number of words in text
    int counterw = 1;
    int let = count_letters(text);
    if (let > 0)
    {
        for (int i = 1, lenght = strlen(text); i < lenght; i++)
        {
            if (text[i - 1] != ' ' && text[i] == ' ' && text[i + 1] != ' ')
            {
                counterw++;
            }
        }
    }
    return counterw;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int counters = 0, lenght = strlen(text), i = 0;
    string each = "";
    int spaces = 0;
    for (i = 0; i < lenght; i++)
    {
        if (text[i] == ' ' && isalpha(text[i - 1]))
        {
            spaces++;
        }
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            int numwor = count_words(each);
            if (numwor > 0)
            {
                numwor++;
                if (spaces < numwor)
                {
                    counters++;
                    each = "";
                    spaces = 0;
                    numwor = 0;
                }
            }
        }
        each += text[i];
    }
    return counters;
}
