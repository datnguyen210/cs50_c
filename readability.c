#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string s);
int count_sentences(string s);
int count_letters(string s);

int main(void)
{
    string text = get_string("TEXT: ");
    int words = count_words(text);
    int letters = count_letters(text);
    int sentences = count_sentences(text);
    // Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    float L = letters * 100.0 / words;
    float S = sentences * 100.0 / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = round(index);
    if (index >= 16)
    {
        printf("Grade 16+");
    }
    else if (index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %d\n", rounded_index);
    }
}

int count_words(string s)
{
    int words = 1;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string s)
{
    int sentences = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

int count_letters(string s)
{
    int letters = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        char lower_char = tolower(s[i]);
        if (lower_char >= 'a' && lower_char <= 'z')
        {
            letters++;
        }
    }
    return letters;
}