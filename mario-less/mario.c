#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int no_block;
    do
    {
        no_block = get_int("Height: "); //get height of blocks from user until he inputs 1-8
    }
    while (no_block <= 0 || no_block >= 9);


    int block = 0;
    int space = 0;
    int n = 1;

    while (block < no_block) //loop until blocks is same as height
    {
        space = (no_block - n);
        block = (no_block - space);
        while (0 > space) // loop until there are no more spaces
        {
            printf(" ");
            space--;
        }
        while (0 > block) //loop until there are no more blocks
        {
            printf("#");
            block--;
        }
        printf("\n"); //new line after each iteration
        n++; //increase count
    }
}