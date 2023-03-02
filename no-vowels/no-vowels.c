// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string word = argv[1];
    printf("%s\n", word);
}

char replace (char n)
{
        switch (n)
    {
        case 'a':
            return '6';

        case 'e':
            return '3';

        case 'i':
            return '1';

        case 'o':
            return '0';
    }
}
