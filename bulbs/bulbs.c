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
    long int decimal_values = string_to_decimal(message);
    printf("decimal values: %li %li %li\n", decimal_values, decimal_values, decimal_values );

    // for NULL - \0
    // if (decimal_values == '\0')
    // {
    //     // 1 means memory allocation failed
    //     printf("Null\n");
    // }

    int binary = decimal_to_binary(decimal_values);
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

    // Updating the input by diving it to 2 (coz its binary)
    for (int i = 0; decimal > 0; i++)
    {
        decimal /= 2;

        // Using modulus operator
        if (decimal % 2 == 0)
        {
            printf("0");
        }
        else if (decimal % 2 != 0)
        {
            printf("1");
        }
    }

    // Neatness
    printf("\n");
    return decimal;
}
