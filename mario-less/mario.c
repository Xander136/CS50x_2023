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

    while (no_block > n) //loop until blocks is same as height
    {
        space = (no_block - n); // 8 - 1 = 7
        block = (no_block - space); // 8 - 7
        while (space > 0) //7  loop until there are no more spaces
        {
            printf(" ");
            space--;
        }
        while (block > 0) //loop until there are no more blocks
        {
            printf("#");
            block--;
        }
        printf("\n"); //new line after each iteration
        n++; //increase count
    }
}