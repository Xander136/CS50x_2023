#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool valid_key(string key);

int main(int argc, string argv[])
{
    // Check for single command-line argument
    // return 1 and message if failed checks
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check for 26 char key
    if (!valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //store key
    string key = argv[1];

    //Prompt the user for a string of plaintext
    string text = get_string("plaintext: ");

    //Output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext
    printf("ciphertext: ");

    // print ciphertext
    // loop over plaintext
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Rotate the character if it's a letter
        // Ci = (Pi + K) % 26
        // VCHPRZGJNTLSKFBDQWAXEUYMOI
        // AB

        char letter = text[i];
        if (isalpha(letter))
        {
            if (isupper(letter))

            printf("%c", letter);
        }
        else
        {
            printf("%c", letter);
        }
    }

    //After outputting ciphertext, print a newline.
    printf("\n");
}

// Function to check if KEY is valid
bool valid_key(string key)
{
    // if key is not 26 characters, return false
    int len = strlen(key);
    if (len != 26)
    {
        return false;
    }
    //change all char to upper
    for (int i = 0, ; i < len; i++)
    {
        key[i] = toupper(key[i]);
    }
    //loop over key
    for (int j = 0; j < len; j++)
    {
        
    }



    }
    return true;
}