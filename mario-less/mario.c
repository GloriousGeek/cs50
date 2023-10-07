#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;

    // Prompt the user for height b/w 1 & 8 inclusive.
    do
    {
        input = get_int("Height: \n");
    }

    while (input < 1 || input > 8);

    // Using nested for loop to print number of rows (i) based on input
    for (int i = 0; i < input; i++)
    {
        // Give space b/w # based on rows
        for (int j = (input - 1); j > i; j--)
        {
            printf(" ");
        }
        // Putting a hash #
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}