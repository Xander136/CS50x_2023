// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
string replace(string n);

int main(int argc, string argv[])
{
    if (argc != 2) //user must input command-line argument
    {
        printf("Missing command-line argument\n");
        return 1;
    }

    string converted_word = replace(argv[1]); //call replace function
    printf("%s\n", converted_word); //print converted word
    return 0;

}



    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");


string replace(string word)
{
    for (characters = )
    {

    }
        switch (n)
        {
            case 'a':
                return '6';
                continue;

            case 'e':
                return '3';
                continue;

            case 'i':
                return '1';
                continue;

            case 'o':
                return '0';
                continue;

            default:
                return 'n';
                continue;
        }
    return converted_word;
}
