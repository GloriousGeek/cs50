#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;
    input = get_int("Height: \n");

    if(input <1 && input > 8)
        {
    //making pyramid with # symbol
    for(int i = 0; i == input; i++)
    {

        printf("#\n");
    }
        }
}