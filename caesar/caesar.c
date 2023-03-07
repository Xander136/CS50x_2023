#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[2] is a digit
    if (argc != 2 || !(only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string text = get_string("plaintext: ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Rotate the character if it's a letter
        // Ci = (Pi + K) % 26
        char letter = text[i];
        if (isalpha(letter))
        {
            if (isupper(letter))
            {
                letter = (((letter - 'A') + key) % 26) + 'A';
            }
            else
            {
                letter = (((letter - 'a') + key) % 26) + 'a';
            }
            printf("%c", letter);
        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");
}

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        char k = s[i];
        if (!(isdigit(k)))
        {
            return false;
        }
    }
    return true;
}
