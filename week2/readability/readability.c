#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculate_level(int sentences, int words, int letters);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    // get input from the user
    string text = get_string("TEXT: ");

    // use the input string and turn it into int count the number of letter
    int letters = count_letters(text);

    // print out the number of letters

    printf("%i letters \n", letters);

    // number of words

    int words = count_words(text);

    // number of sentences
    int sentences = count_sentences(text);

    // calculate grade level
    int gradeLevel = calculate_level(sentences, words, letters);

    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLevel);
    }
}

// use the input string and calcute the number of letters in that string

int count_letters(string text)
{
    int num = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            num++;
        }
    }

    return num;
}

// count the number of words

int count_words(string text)
{
    int num2 = 0;

    if (strlen(text) > 1)
    {
        num2 += 1;
    }

    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == ' ')
        {
            num2++;
        }
    }

    return num2;
}

// calculate the number of sentences

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// calculates the grade level using  Coleman-Liau index.
int calculate_level(int sentences, int words, int letters)
{
    float L = ((float) letters / words) * 100.0;
    float S = ((float) sentences / words) * 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int gradeLevel = (int) round(index);

    return gradeLevel;
}
