#include <stdio.h>
#include <cs50.h>
//asks for their name, then greet
int main(void)
{
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}