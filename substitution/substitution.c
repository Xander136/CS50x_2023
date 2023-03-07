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
    // printf("ciphertext: ");


    int len = strlen(text);     //length of plaintext
    char ciphertext[len + 1];   //array for ciphertext with len of plaintext +1 for terminator
    int index;                  //index for difference of plaintext character - Decimal 'a'
    for (int i = 0; i < len; i++) // loop over plaintext
    {
        if (islower(text[i]))   //if plaintext character is lowercase
        {
            index = text[i] - 'A';  //index is current plaintext character - A
            ciphertext[i] = key[index]; //equivalent ciphertext
            if (isupper(ciphertext[i]))
            {
                ciphertext[i] += 32; //difference between upper and lower cases
            }
        }
        if (isupper(text[i]))
        {
            index = text[i] - 'a';
            ciphertext[i] = key[index];
            if (islower(ciphertext[i]))
            {
                ciphertext[i] += 32;
            }
        }
    }

    ciphertext[len] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    //After outputting ciphertext, print a newline.
    // printf("\n");
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
    for (int i = 0; i < len; i++)
    {
        key[i] = toupper(key[i]);
    }
    //loop over key
    for (int i = 0; i < len; i++)
    {
        //check if character is Alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }
        //check for duplicates
        for (int j = i + 1; j < len; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}