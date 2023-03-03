#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);
    int letters = count_letters(text);
    printf("%i\n", letters);

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