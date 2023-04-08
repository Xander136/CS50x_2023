#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // check if there is exactly one command-line argument
    if (argc != 2)
    {
        // If program is not executed with exactly one command-line argument, remind the user of correct usage
        printf("Usage: ./recover filename\n");
        return 1;
    }
    // Open memory card
    // If the forensic image cannot be opened for reading,
    // your program should inform the user as much, and main should return 1.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open file: %s\n", argv[1]);
        return 1;
    }

    // read every byte until end of card
    char buffer[513];
    fread(buffer, 512, 1, file);

    if (!jpeg_start(buffer))
    {
        continue;
    }
    
        // read 512 bytes into a buffer
        // if start of new JPEG
            // if first JPEG
                // write 1st file
                // close file writing into
            // if 2nd open new file
                // write 2nd file






    // filename for generated image
    for (int file_number = 0; file_number < 10; file_number++)
    {
        char buffer[8];
        sprintf(buffer, "%03i.jpg", file_number);
        printf("%s\n", buffer);
    }


}