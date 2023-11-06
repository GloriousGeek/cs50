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
    // Reads data from the input_file file and stores it in the buffer
    while (fread(buffer, 512, 1, input_file) == 1)
    {
        // Check for the start of JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] & 0xf0 == 0xe0)
        {
            // If JPEG is already open, close it.
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create new file
            char new_file[BYTE];

            // String formatting to new_file
            sprintf(new_file, "%03i.jpg", jpeg_count);
            output_file = fopen(new_file, "wb");
            jpeg_count++;
        }

        if (output_file != NULL)
        {
            // Write data in buffer from the output_file
            fwrite(buffer, 512, 1, output_file);
        }
    }

    // Close file
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    fclose(input);
    return 0;
}
