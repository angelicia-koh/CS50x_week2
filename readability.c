#include <cs50.h>
#include <ctype.h>
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
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);


    // L is the average number of letters per 100 words in the text:
    // that is, the number of letters divided by the number of words, all multiplied by 100.
    float l = (letters / words) * 100;
    // S is the average number of sentences per 100 words in the text:
    // that is, the number of sentences divided by the number of words, all multiplied by 100.
    float s = (sentences / words) * 100;
    // Compute the Coleman-Liau index
    float Coleman_Liau_Index = (0.0588 * l) - (0.296 * s) - 15.8;


    // Print the grade level
    if (Coleman_Liau_Index >= 16)
    {
        printf("Grade 16+\n");
    }


    else if (Coleman_Liau_Index < 1)
    {
        printf("Before Grade 1\n");
    }


    else
    {
        // round(): round a number to the nearest integer
        int grade_level = round(Coleman_Liau_Index);
        printf("Grade %i\n", grade_level);
    }
}


int count_letters(string text)
{
    // Return the number of letters in text
    int letters = 0;


    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }


    return letters;
}


int count_words(string text)
{
    // Return the number of words in text
    int words = 0;


    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            words += 1;
        }
    }


    int total_words = words + 1;
    return total_words;
}


int count_sentences(string text)
{
    // Return the number of sentences in text
    int sentence = 0;


    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence += 1;
        }
    }


    return sentence;
}



