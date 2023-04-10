#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;
int jpeg_header(BYTE buffer[]);

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
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("Can't open file: %s\n", argv[1]);
        return 1;
    }

    // declare variables
    int counter = 0;
    char filename[8];
    BYTE buffer[512];
    FILE *filePointer = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, inputFile) == BLOCK_SIZE)
    {
        if (jpeg_header(buffer) == 0)
        {
            if (filePointer != NULL)
            {
                fclose(filePointer);
            }
            sprintf(filename, "%03i.jpg", counter);
            filePointer = fopen(filename, "w");
            counter++;
        }
        else if (filePointer != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, filePointer);
        }

    }
    if (filePointer != NULL)
    {
        fclose(filePointer);
    }
    if (inputFile != NULL)
    {
        fclose(inputFile);
    }
    return 0;
}

// check if start of JPEG
int jpeg_header(BYTE buffer[])
{
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}