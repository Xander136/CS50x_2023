// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    //initialize bool variables
    bool uppercase_letter = false;
    bool lowercase_letter = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0, n = strlen(password); i < n; i++) //iterate over string
    {
        if (isupper(password[i])) //check if uppercase
        {
            uppercase_letter = true;
        }
        if (islower(password[i])) //check if lower case
        {
            lowercase_letter = true;
        }
        if (isdigit(password[i])) //check of is a digit
        {
            number = true;
        }
        if (ispunct(password[i])) //check if symbol
        {
            symbol = true;
        }
    }
    //if all conditions met, return true, else return false
    if (uppercase_letter == true && lowercase_letter == true && number == true && symbol == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
