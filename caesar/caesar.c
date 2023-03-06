#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    // Make sure every character in argv[2] is a digit
    if (only_digits(argv[2]) == false)
    {
        printf("Usage: ./caesar key\n");
    }
    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext

    // For each character in the plaintext:

        // Rotate the character if it's a letter
}

bool only_digits(string s);
{
    bool digit;
    for (int i = 0, len = strlen(s), i++)
    {
        if (isdigits(s[i]))
        {
            digits = true;
        }
    }
    return digit;
}