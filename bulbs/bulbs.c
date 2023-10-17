#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int string_to_decimal(string message);
int decimal_to_binary(int decimal);

int main(void)
{
    // User input
    string message = get_string("Message: ");

    // Call string function to get decimal. int* is a pointer not int

    int decimal_values = string_to_decimal(message);
    printf("decimal values: %i\n", decimal_values);

        // Length of string
        // int length = strlen(message);

        // // declaring a variable to use in a for loop and return in the function
        // int decimal_value;

        // for (int i = 0; i < length; i++)
        //     {
        //         // Updating decimal_value w every iteration
        //         decimal_value = message[i];
        //         printf("%i\n", decimal_value);
        //         printf("%i\n", i);
        //     }

    int binary = decimal_to_binary(decimal_values);
    printf("binary: %i\n", binary);
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

int string_to_decimal(string message)
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
    }

    return decimal_value;
}

int decimal_to_binary(int decimal)
{
    int binary[BITS_IN_BYTE];

    // Updating the input by diving it to 2 (coz its binary)
    for (int i = 0; decimal > 0; i++)
    {
        binary[i] = decimal % 2;

        printf("%i", binary[i]);

        // Updating variable
        decimal /= 2;
    }

    for (int j = 8; j > 0; j--)
    {
        printf("%i", binary[j]);
    }

    // Neatness
    printf("\n");

    return decimal;
}
