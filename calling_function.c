#include <stdio.h>
#include <cs50.h>

// Declaring function
int add_two_ints(int a, int b);

int main(void)
{
    // Prompt user
    int x = get_int("Give me an integer: ");
    int y = get_int("Give me another integer: ");

    // Calling the function
    int z = add_two_ints(x, y);

    // Returning the value. Output
    printf("The sum of %i and %i is: %i\n", x, y, z);
}

// Defining function
int add_two_ints(int a, int b)
{
    return a + b;
}