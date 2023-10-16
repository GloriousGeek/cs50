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
    int* decimal_values = string_to_decimal(message);

    if (decimal_values == NULL)
    {
        return NULL:
    }

    // Print decimal values
    for (int i = 0; decimal_values != 0; i++)
    {
        printf("Decimal: %i\n", decimal_values[i]);
    }

    // Free allocated memory
    free(decimal_values);
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

    // Array. +1 for the null terminator (\0). malloc for dynamic memory
    int* decimal_array = (int*)malloc((length + 1) * sizeof(int));

    if (decimal_array == NULL)
    {
        // Memory allocation failed
        return NULL;
    }

    for (int i = 0; i < length; i++)
    {
        int decimal_array[i];

        decimal_array[i] = int message[i];
        printf("%i\n", decimal_array);

    }

    return decimal_array;
}
