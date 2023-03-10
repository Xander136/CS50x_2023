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

//hello
string replace(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++) //iterate over the letters
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;
        }
    }
    return word;//return converted word
}
