#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int string_to_binary(string message);

int main(void)
{
    // User input
    string message = get_string("Message: ");

    // Call string function to get decimal. int* is a pointer not int

    string_to_binary(message);
    // printf("decimal values: %i\n", decimal_values);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

int string_to_binary(string message)
{
    // Length of string
    int length = strlen(message);

    // declaring a variable to use in a for loop and return in the function
    int decimal_value;


    for (int i = 0; i < length; i++)
    {
        // Updating decimal_value w every iteration
        decimal_value = message[i];
        printf("%i\n", decimal_value);
        printf("%i\n", i);

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            
        }

    }

    // Size 8 array initializing at 0 values
    int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // Updating the input by diving it to 2 (coz its binary)
    for (int i = 0; decimal_value > 0; i++)
    {
        decimal_value = message[i];

        // Updating binary array with modulous
        binary[i] = decimal_value % 2;

        printf("%i", binary[i]);

        // Updating variable
        decimal_value /= 2;
    }

    printf("\n");

    // Inverting the binary value from right to left
    for (int k = BITS_IN_BYTE - 1; k >=  0; k--)
    {
        // Calling print_bulb func
        print_bulb(binary[j]);
    }

    // Neatness
    printf("\n");

    return decimal_value;
}

