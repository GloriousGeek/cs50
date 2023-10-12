#include <cs50.h>
#include <stdio.h>

// Declaring the function
int dynamic_array[];

// Declaring a global variable
int length;

int main(void)
{
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);

    int dynamic_array[];
    {
    // Initial value of array should be 1
    dynamic_array[0] = 1;

    printf("%i\n", dynamic_array[0]);

    for (i = 0; i < length, i++)
    {
        // Give 2 times the previous value
        dynamic_array[i] = 2 * dynamic_array[i -1];

        // Printing the value
        printf("%i\n", dynamic_array[i]);
    }

    // Calling the function
    int array = dynamic_array[length];
    }

// Defining the function
int dynamic_array[]
{
    // Initial value of array should be 1
    dynamic_array[0] = 1;

    printf("%i\n", dynamic_array[0]);

    for (i = 0; i < length, i++)
    {
        // Give 2 times the previous value
        dynamic_array[i] = 2 * dynamic_array[i -1];

        // Printing the value
        printf("%i\n", dynamic_array[i]);
    }
}