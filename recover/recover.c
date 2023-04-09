#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;
char* filename(int img_count);
bool jpeg_start(BYTE *buffer);

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
    malloc(buffer[512]);
    bool file_open = false;

    // read every byte until end of card
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (jpeg_start(*buffer) == true)
        {
            printf("nice\n");
        }
        // if (jpeg_start(*buffer))
        // {
        //     printf("nice\n");
        // }
    }






}

// create file name
char* filename(int jpeg_count)
{
    // filename for generated image
    char *buffer = malloc(8);
    buffer[7] = '\0';
    sprintf(buffer, "%03i.jpg", jpeg_count);
    return buffer;
}



// check if start of JPEG
bool jpeg_start(BYTE *buffer)
{
    if (!(buffer[0] == 0xff))
    {
        return false;
    }
    if (!(buffer[1] == 0xd8))
    {
        return false;
    }
    if (!(buffer[2] == 0xff))
    {
        return false;
    }
    if (!((buffer[3] & 0xf0) == 0xe0))
    {
        return false;
    }
    return true;
}