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
    int bits[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // iterate over string
    for (int i = 0, len = strlen(message); i < len; i++)
    {
        int decimal = message[i];
        for (int j = BITS_IN_BYTE - 1, decimal > 0; j--)
        {
            bits[j] = decimal % 2;
            decimal = decimal / 2;
        }

        int bit = (decimal * 2 ^ 4);
        //print binary
        //double pow(double 2, double ylen-1);

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
