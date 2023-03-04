#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    //ask user input
    string message = get_string("Message: ");
    printf("%s\n", message);

    //convert string
    // iterate over string
    for (int i = 0, len = strlen(message); i < len; i++)
    {
        int decimal = message[i];
        int bit = (1 * 2 ^ 4);
        //print binary
        print_bulb(bit);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
