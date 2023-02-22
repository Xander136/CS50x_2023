#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min; // ask for minimum number until you get a value greater than 1
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max; // ask for max number until you get a value greater than min
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++) //loop through min to max
    {
        if (prime(i))
        {
            printf("%i\n", i); // print if Prime number
        }
    }
}

bool prime(int number)
{
    if ((number / 2) % 0 && (number - 1) / number % 0);
    return false;
}
