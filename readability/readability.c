#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentence(string text);

int main(void)
{
    //get string of text
    string text = get_string("Text: ");
    // printf("%s\n", text);

    //count letters
    int letters = count_letters(text);
    //print number of letters
    printf("%i letters\n", letters);

    //count words
    int words = count_words(text) + 1;
    //print number of words
    printf("%i words\n", words);

    //count sentences
    int sentences = count_sentence(text);
    //print number of sentences
    printf("%i sentences\n", sentences);
/*
27.300252
8.45672

3.625
21.315





 */
    //Compute Coleman-Liau index
    float l = (float) (letters / words) * 100;
    float s = (float) (sentences / words) * 100;
    float index = (float) 0.0588 * l - 0.296 * s - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else //Grade 1 to 15
    {
        printf("Grade %i\n", (int) index);
    }
}

//Function for counting letters from user input
int count_letters(string text)
{
    int letters = 0;
    //Loop over the string
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

//Function for counting words from user input
int count_words(string text)
{
    int words = 0;
    //Loop over the string
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i]) == ' ')
        {
            words += 1;
        }
    }
    return words;
}

//Function for counting sentences from user input
int count_sentence(string text)
{
    int sentences = 0;
    //Loop over the string
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i]) == '!' || (text[i]) == '.' || (text[i]) == '?' )
        {
            sentences += 1;
        }
    }
    return sentences;
}