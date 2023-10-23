#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Recursion instead of for loop

int factorial(int number);

int main(void)
{
    // Prompt
    int n = get_int("Enter a number: ");
    printf("%i\n", factorial(n));
}

int factorial(int number)
{
    // Base case
    if (number == 1)
    {
        return 1;
    }

    // n * factorial (n - 1) see week3 section 55mins.
    return number * factorial(number - 1);
}