#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Prompt user for number of cents
    int cents = 0;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    return cents;
}


int calculate_quarters(int cents)
{
    // TODO

    int quarters = 0; //initialize quarter variable

    if (cents % 25 == 0)         //if cents is divisible by 25,
    {
        quarters = (cents / 25); //divide cents by 25 then store to quarters
    }
    else
    {
        quarters = (cents / 25);            //divide cents by 25 to get number of quarters
        // cents = cents - (quarters * 25);    //subtract total value of quarters from cents
    }
    return quarters; //return quarters
}

int calculate_dimes(int cents)
{
    int dimes = 0; //initialize quarter variable

    if (cents % 10 == 0)         //if cents is divisible by 10,
    {
        dimes = (cents / 10); //divide cents by 10 then store to quarters
    }
    else
    {
        dimes = (cents / 10);            //divide cents by 10 to get number of quarters
        // cents = cents - (dimes * 10);    //subtract total value of dimes from cents
    }
    return dimes; //return dimes

}

int calculate_nickels(int cents)
{
    int nickels = 0; //initialize nickels variable

    if (cents % 5 == 0)         //if cents is divisible by 5,
    {
        nickels = (cents / 5); //divide cents by 5 then store to nickels
    }
    else
    {
        nickels = (cents / 5);            //divide cents by 5 to get number of nickels
        // cents = cents - (nickels * 5);    //subtract total value of nickels from cents
    }
    return nickels; //return nickels
}

int calculate_pennies(int cents)
{
    int pennies = 0; //initialize pennies variable

    if (cents % 5 == 0)         //if cents is divisible by 5,
    {
        pennies = (cents / 5); //divide cents by 5 then store to pennies
    }
    else
    {
        pennies = (cents / 5);            //divide cents by 5 to get number of pennies
        // cents = cents - (pennies * 5);    //subtract total value of pennies from cents
    }
    return pennies; //return pennies
}
