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
        //convert to decimal
        int bits[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int decimal = message[i];
        for (int j = BITS_IN_BYTE - 1; decimal > 0; j--)
        {
            //store 1(with remainder) or 0(no remainder) from right most bit
            bits[j] = decimal % 2;
            decimal = decimal / 2;
        }
        //print binary
        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            print_bulb(bits[k]);
        }
        //print new line for each bit
        printf("\n");
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
