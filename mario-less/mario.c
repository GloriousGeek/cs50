#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;

    do
    {
        input = get_int("Height: \n");
    }

    while (input < 1 || input > 8); //when its true, it would keep prompting the user

    //using nested for loop
    for(int i = 0; i < input; i++) //to print number of rows based on input
    {
        for (int j = (input - 1) ; j > i; j--) //to give space b/w # based on rows
        {
            printf(" ");
        }

         for (int k = 0; k < i + 1; k++) //to put a hash #
        {
            printf("#");
        }

        printf("\n");
    }

}