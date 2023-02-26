#include <cs50.h>
#include <stdio.h>

void print_left_space(int no_space);
void print_block(int no_block);
void print_gap();
int get_space(int no_block, int n);

int main(void)
{
    int no_block;
    do
    {
        no_block = get_int("Height: "); //get height of blocks from user until he inputs 1-8
    }
    while (no_block <= 0 || no_block >= 9);

    /* declare variables */
    int no_space = 0;
    int block = 1;

    do
    {
        no_space = get_space(no_block, block);   // get number of spaces using function
        print_left_space(no_space);         // print number of spaces
        print_block(block);                 // print number of blocks on the left
        print_gap();                        // print 2 spaces using function
        print_block(block);                 // print number of blocks on the right
        printf("\n");                       // print new line
        block++;                            // increment number of blocks
    }
    while (no_block >= block); //loop until blocks is same as number of blocks entered from user input

}

int get_space(int no_block, int block) //print left spaces
{
    int no_space = (no_block - block);
    return no_space;
}

void print_left_space(int no_space) //print left spaces
{
    while (no_space > 0)
    {
        printf(" ");
        no_space--;
    }
}

void print_block(int no_block) //print blocks
{
    while (no_block > 0)
    {
        printf("#");
        no_block--;
    }
}

void print_gap() //print gap
{
    printf("  ");
}