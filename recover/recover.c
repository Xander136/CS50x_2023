#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;
bool jpeg_header(BYTE buffer[]);

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

    // read into buffer the current block until there are no more blocks to read
    while (fread(buffer, 1, BLOCK_SIZE, inputFile) == BLOCK_SIZE)
    {
        // if current block is a jpeg header
        if (jpeg_header(buffer))
        {
            // check if there is currently a file open
            if (filePointer != NULL)
            {
                // close current file
                fclose(filePointer);
            }
            // create filename
            sprintf(filename, "%03i.jpg", counter);
            // open new file to write into
            filePointer = fopen(filename, "w");
            // increase counter for images found
            counter++;
        }

        // if there is a file opened
        if (filePointer != NULL)
        {
            // write into the file
            fwrite(buffer, 1, BLOCK_SIZE, filePointer);
        }
    }
    // close last file
    if (filePointer != NULL)
    {
        fclose(filePointer);
    }
    // close the input file
    if (inputFile != NULL)
    {
        fclose(inputFile);
    }
    return 0;
}

// check if start of JPEG
bool jpeg_header(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}