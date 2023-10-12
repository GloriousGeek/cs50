#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);

    // Declare our array
    int dynamic_array[length];

    // Set the first value
    dynamic_array[0] = 1;

    printf("%i\n", dynamic_array[0]);

    for (int i = 0; i < length, i++)
    {
        // Give 2 times the previous value
        dynamic_array[i] = 2 * dynamic_array[i -1];

        // Printing the value
        printf("%i\n", dynamic_array[i]);
    }

}