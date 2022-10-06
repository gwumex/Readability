#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
void result(int words, int letters, int sentences);

int main(void)
{
    string string;
    string = get_string("Text: ");
    int letters = count_letters(string);
    int words = count_words(string);
    int sentences = count_sentences(string);
    result(words, letters, sentences);
}

int count_letters(string s)
{
    int letters = 0;
    for (int i = 0; s[i]; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    int words = 1;
    for (int i = 0; s[i] != '\0'; i++)
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
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

void result(int words, int letters, int sentences)
{
    float l = (float)letters / words * 100;
    float s = (float)sentences / words * 100;
    int index = round((float)0.0588 * l - 0.296 * s - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}