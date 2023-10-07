#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for starting population size of not less than 9
    int start_size;
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);

    // Prompt for end size not less than the start size
    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    }
    while (end_size < start_size);

    // For number of years until we reach threshold, i.e, annual population = end size.
    int annual_pop = start_size;

    int year;
    for (year = 0; annual_pop < end_size; year++)
    {
        annual_pop = annual_pop + (annual_pop / 3) - (annual_pop / 4);
    }

    printf("Years: %i\n", year);

    return 0;
}
