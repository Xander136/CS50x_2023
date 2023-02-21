// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    //total_bill = bill + tax
    float tax_amount = bill * (tax/100);
    float total_bill = (bill + tax_amount);
    //tip_amount = total_bill + tip_total
    float tip_total = total_bill * (tip/100);
    total_bill += tip_total;
    //half = plus tax / 2
    total_bill = total_bill/2;
    return total_bill;
}
