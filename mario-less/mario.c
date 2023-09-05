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
    for(int i = 0; input > 0 && input < 9; i++)
    {
        for (int j = 0; input > 0 && input < 9; j++)
        {

        input++;
        printf("#\n");
        }
    }

}