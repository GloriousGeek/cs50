#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open memory card by declaring a pointer
    FILE *file = fopen(argv[1], "r");
    if (file != NULL)
    {
        return 2;
    }

    // Read data from memory card into buffer in 512 byte chunks
    unsigned char buffer[512];

    // Initialize variables for output file and counter
    FILE *output = NULL;
    int jpeg_count = 0;

    // Iterate over memory card's data
    while fread(buffer, 512, 1, file)

}
