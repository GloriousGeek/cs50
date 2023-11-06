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

    // Read data from memory card
    fread(storedata[], 512, 512, FILE *file)

    // Iterate over memory card's data
    if (file )
}
