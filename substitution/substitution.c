#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool valid_key(string key);

int main(int argc, string argv[])
{
    // Check for single command-line argument or
    // Check for 26 char key
    // return 1 and message if failed checks
    if (argc != 2 || !(valid_key(argv[1])))
    {
        printf("Usage: ./substitution key\n");
    }




    //Prompt the user for a string of plaintext

    //Output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext

    //After outputting ciphertext, print a newline.

}

// Function to check if KEY is valid
bool valid_key(string key)
{
    for (int i = 0, lebn = strlen(key); i < len; i++)
    {
        char letter
    }
}