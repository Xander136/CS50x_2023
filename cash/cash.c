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
    // 25 = 1
    // 50 = 1
    int quarters = 0; //initialize quarter variable



    if (cents % 25 == 0)         //if cents is divisible by 25,
    {
        quarters = (cents / 25); //divide cents by 25 then store to quarters
    }
    else
    {
        quarters = (cents / 25);            //divide cents by 25 to get number of quarters
        cents = cents - (quarters * 25);    //subtract total value of quarters from cents
    }
    return quarters; //return quarters
}

int calculate_dimes(int cents)
{
    // TODO
    return 0;
}

int calculate_nickels(int cents)
{
    // TODO
    return 0;
}

int calculate_pennies(int cents)
{
    // TODO
    return 0;
}
