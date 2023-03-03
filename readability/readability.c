#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    //get string of text
    string text = get_string("Text: ");
    // printf("%s\n", text);
    //count letters
    int letters = count_letters(text);
    //print number of letters
    printf("%i letters\n", letters);

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