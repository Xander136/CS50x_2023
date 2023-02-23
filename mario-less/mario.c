#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int no_block;
    do
    {
        no_block = get_int("Height: ");
    }
    while (no_block <= 0 || no_block >= 9);
}

int block;
int space;
while (block < no_block)
{
    space = (no_block - 1);
    block = (no_block - space);
    printf("%i%i)
}