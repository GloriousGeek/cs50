#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for the height of the pyramid
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Build the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print hashes for left-aligned side
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Add space between the two sides
        printf("  ");

        // Print hashes for right-aligned side
        for (int j = 0; j <= i; j--)
        {
            printf("#");
        }

        // Newline to move to the next row
        printf("\n");
    }

    return 0;
}
