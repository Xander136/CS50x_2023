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
    //get bill + tax
    float tax_amount = (bill * (tax / 100));
    float bill_with_tax = tax_amount + bill;
    //get bill w/ tax + tip
    float tip_converted = (float) tip / 100;
    float tip_amount = (bill_with_tax * tip_converted);
    //divide by 2
    float total_bill = (bill_with_tax + tip_amount) / 2;
    return total_bill;
}
