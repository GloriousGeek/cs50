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
    FILE *input_file = fopen(argv[1], "r");
    if (file != NULL)
    {
        return 2;
    }

    typedef uint8_t BYTE;
    
    // Read data from memory card into buffer in 512 byte chunks
    unsigned char buffer[512];

    // Initialize variables for output file and counter
    FILE *output_file = NULL;
    int jpeg_count = 0;

    // Iterate over memory card's data
    // Reads data from the file file and stores it in the buffer
    while (fread(buffer, 512, 1, input_file) == 1)
    {
        if (1 )
    }

}
