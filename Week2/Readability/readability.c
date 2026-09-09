#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main()
{
    int i;
    float number_letter;
    float number_sentences;
    float number_words;
    string text = get_string("Text: ");

    i = 0;
    number_letter = 0;
    number_sentences = 0;
    number_words = 1;

    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            number_letter++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            number_sentences++;
        }
        else if (isblank(text[i]))
        {
            number_words++;
        }
        i++;
    }

    float index = (0.0588 * 100 * (number_letter / number_words)) -
                  (0.296 * 100 * (number_sentences / number_words)) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %.f\n", round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}
