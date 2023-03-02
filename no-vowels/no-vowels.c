// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
char replace (char n);

int main(int argc, string argv[])
{
    string word = argv[1];
    printf("%s\n", word);
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        string character[] = replace(word[i]);
    }
    printf("%s\n", character)
}

char replace (char n)
{
        switch (n)
    {
        case 'a':
            return '6';
            break;

        case 'e':
            return '3';
            break;

        case 'i':
            return '1';
            break;

        case 'o':
            return '0';
            break;

        default:
            break;

    }
}
