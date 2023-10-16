#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

const int N =

void print_bulb(int bit);
int string_to_decimal(string message);

int main(void)
{
    // User input
    string message = get_string("Message: ");

    // Call string function to get decimal
    int decimal_values = string_to_decimal(message);
    printf("Decimal: %i\n", decimal_values);

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
    int decimal;

    // Defining an array
    int decimal_array[N];

    // Length of string
    int length = strlen(message);

    for (int i = 0; i < length; i++)
    {
        int decimal_array[i];

        decimal_array[i] = message[i];
        printf("%i\n", decimal_array);

    }

    return decimal_array;
}
