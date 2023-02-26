#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long card_no = 0;
    do //get credit card number
    {
        card_no = get_long("Number: ");
    }
    while(card_no < 1);

    // int card_type = 0;
    //sample 378282246310005
    //       100000000000000

    //15-digit numbers & start with 34 or 37
    if (card_no % 100000000000000 == 34 || card_no % 100000000000000 == 37)
    {
        printf("AMEX\n");
    }
    // //16-digit numbers & start with 51, 52, 53, 54, or 55
    // if (card_type == 2)
    // {
    //     printf("MASTERCARD\n");
    // }
    // //13- and 16-digit numbers & start with 4
    // if (card_type == 3")
    // {
    //     printf("VISA\n");
    // }
    // else
    // {
    //     printf("INVALID\n");
    // }
}