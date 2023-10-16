#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int string_to_binary(string message);

int main(void)
{
    // User input
    string message = get_string("Message: ");

    // Call string function to get decimal
    int decimal = string_to_binary(message);
    printf("Decimal: %i\n", decimal);

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


    // Length of string
    int length = strlen(message);

    for (int i = 0; i < length; i++)
    {
        int decimal_array[i];

        decimal = message[i];
        printf("%i\n", decimal);

    }

    return decimal_array;
}