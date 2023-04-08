#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check if there is exactly one command-line argument
    if (argc != 2)
    {
        // If program is not executed with exactly one command-line argument, remind the user of correct usage
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // If the forensic image cannot be opened for reading,
    // your program should inform the user as much, and main should return 1.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open file: %s\n", argv[1]);
        return 1;
    }
    
    // filename for generated image
    for (int file_number = 0; file_number < 10; file_number++)
    {
        char buffer[8];
        sprintf(buffer, "%03i.jpg", file_number);
        printf("%s\n", buffer);
    }
}