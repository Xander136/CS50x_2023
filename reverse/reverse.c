#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"


int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *inputFile = argv[1];
    FILE *inputPtr = fopen(inputFile, "r");
    if (inputPtr == NULL)
    {
        printf("Unable to open file: %s\n", inputFile);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, inputPtr);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Invalid file: %s\n", inputFile);
        return 1;
    }

    // Open output file for writing
    // TODO #5
    char *outputFile = argv[2];
    FILE *outPtr = fopen(outputFile, "w");
    if (outPtr == NULL)
    {
        printf("Unable to open file: %s\n", outputFile);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, outPtr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    // declare an array to store each block we read in
    BYTE buffer[block_size];
    // go to end of file
    fseek(inputPtr, block_size, SEEK_END);

    // read each audio data from the end of the file
    while (ftell(inputPtr) - block_size > sizeof(header))
    {
        // write to outfile
        // move back 2 block_sizes
        fseek(inputPtr, - 2 * block_size, SEEK_CUR);
        fread(&buffer, block_size, 1, inputPtr);
        fwrite(&buffer, block_size, 1, outPtr);

    }
    // close input file
    if (inputPtr != NULL)
    {
        fclose(inputPtr);
    }
    // close output file
    if (outPtr != NULL)
    {
        fclose(outPtr);
    }
}

int check_format(WAVHEADER header)
{
    // TODO #4
    return (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E');
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}