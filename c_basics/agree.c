#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree?\n ");

    // Check whether agreed. Use single comas ' for Char. || is the OR operator in C
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed\n ");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed\n ");
    }
}