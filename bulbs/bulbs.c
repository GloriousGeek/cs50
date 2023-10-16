#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

// const int N =

void print_bulb(int bit);
int string_to_decimal(string message);

int main(void)
{
    // User input
    string message = get_string("Message: ");

    // Call string function to get decimal. int* is a pointer not int
    int decimal_values = string_to_decimal(message);

    if (decimal_values == '\)
    {
        // 1 means memory allocation failed
        printf("Null\n");
    }

    // Print decimal values
    for (int i = 0; decimal_values[i] != '\0'; i++)
    {
        printf("%i\n", decimal_values[i]);
    }
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
    int decimal_value;

    for (int i = 0; i < length; i++)
    {
        int decimal_value = message[i]
    }

    return decimal_array;
}
