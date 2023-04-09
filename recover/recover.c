#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;
char* filename(int img_count);
int jpeg_start(BYTE buffer[]);

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
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open file: %s\n", argv[1]);
        return 1;
    }

    // counter for images recovered
    int jpeg_count = 0;

    // create a new type to store a 512 byte of data
    int BLOCK_SIZE = 512;
    BYTE buffer[512];
    bool found_new = false;


    // read every byte until end of card
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (jpeg_start(buffer) == 0)
        {
            file_open = true;
            char *filename = filename(jpeg_count);
            FILE *img = fopen(filename, "w");
            fwrite(buffer, 1, BLOCK_SIZE, filename);
        }
        else if (file open)

    }






}

// create file name
char* filename(int jpeg_count)
{
    // filename for generated image
    char *filename = malloc(8);
    sprintf(filename, "%03i.jpg\0", jpeg_count);
    return filename;
}



// check if start of JPEG
int jpeg_start(BYTE buffer[])
{
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}