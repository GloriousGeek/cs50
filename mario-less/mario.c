#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;

    do
    {
        input = get_int("Height: \n");
    }

    while (input < 1 || input > 8);

    //making pyramid with # symbol
    char symbol;
    symbol = '#';

    //using nested for loop
    for(int i = 0; i < input; i++)
    {
        printf(".");
        for (int k = 0; k < i; k++)
        {
            print(".");
        }

         for (int j = 0; j < i + 1; j++)
        {

        printf("#");


        }

        printf("\n");
    }

}