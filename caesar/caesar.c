#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[2] is a digit
    if (argc != 2 || !(only_digits(argv[2])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext

    // For each character in the plaintext:

        // Rotate the character if it's a letter
}

bool only_digits(string s)
{
    bool digit;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isdigit(s[i]))
        {
            digit = true;
        }
    }
    return digit;
}