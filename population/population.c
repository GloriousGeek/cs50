#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_int("Enter starting population size\n ");
    

    // llmas value should not be less than 9
    while (start_size < 9)
    {
        printf("Population Start size should at least be 9\n");
        printf(start_size);
    }

    // TODO: Prompt for end size
    int end_size = get_int("Enter ending population size\n ");
    if (end_size < start_size)
    {
        printf(end_size);
    }

    // TODO: Calculate number of years until we reach threshold
    // llamas born each year. 
    start_size = start_size + (start_size/3) - (start_size/4);
    // truncate 

    // llamas pass away each year
    int annual_death = start_size/4


    // TODO: Print number of years
    printf("Years: ")
}
