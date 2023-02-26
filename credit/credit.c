#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_no = 0;
    do //get credit card number
    {
        card_no = get_long("Number: ");
    }
    while(card_no < 1);

    string card_type = "AMEX";

    //15-digit numbers & start with 34 or 37
    if (card_type == "AMEX")
    {
        printf("AMEX\n");
    }
    //16-digit numbers & start with 51, 52, 53, 54, or 55
    if (card_type == "MASTERCARD")
    {
        printf("MASTERCARD\n");
    }
    //13- and 16-digit numbers & start with 4
    if (card_type == "VISA")
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}