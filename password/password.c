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

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isupper(password[i]))
        {
            uppercase_letter = true;
        }
        if (islower(password[i]))
        {
            lowercase_letter = false;
        }
        if (isdigit(password[i]))
        {
            number = true;
        }
        if (ispunct(password[i]))
        {
            symbol = true;
        }
    }
    if (uppercase_letter == true && lowercase_letter == true && number == true && symbol == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
