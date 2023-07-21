#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("Write Case: ");
    switch(x)
    {
        case 1:
        printf("One!\n");
        break;
        case 2:
        printf("Two!\n");
        break;
        case 3:
        printf("Three!\n");
        break;
    }

}