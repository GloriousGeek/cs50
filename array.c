#include <cs50.h>
#include <stdio.h>

// Declaring the function
int dynamic_array[];

int main(void)
{
    int length
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);

    // Calling the function
    int array = dynamic_array[length];
}

// Defining the function
int dynamic_array[]
{

    for (i = 0; i < length, i++)
    {
        // Initial value of array should be 1
        int dynamic_array[i] = 1;

        printf("%i\n", dynamic_array[i]);

        // Give 2 times the previous value
        dynamic_array[i] *= 2;
    }
}