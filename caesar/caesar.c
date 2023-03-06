#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc == 2)
    {
        // Make sure every character in argv[1] is a digit
        string key = argv[2];
        for (int i = 0, len = strlen(argv[2]); i < len; i++)
        {
            if (isdigit(key[i]) != 'True') //check if digit, else print usage
            {
                printf("Usage: ./caesar key\n");
                break;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }

    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext

    // For each character in the plaintext:

        // Rotate the character if it's a letter
}
