#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    // do while loop
    int start_size;
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);
        // printf("start size: start_size");


    // llmas value should not be less than 9


    // TODO: Prompt for end size
    int end_size;
    do
    {
    end_size = get_int("End Size: ");
    }
    while (end_size < start_size);


    // TODO: Calculate number of years until we reach threshold
    // llamas born each year = n/3

    int annual_pop = start_size;
    // printf("population %i\n"; annual_pop);
    // int year=0;
    // while (annual_pop <end_size)
    // {
    //  annual_pop = annual_pop + (annual_pop/3) - (start_size/4);
    //  year++;
    // }
    int year;
    for (year = 0; annual_pop < end_size ; year++)
    {
        annual_pop = annual_pop + (annual_pop/3) - (annual_pop/4);

        printf("Pop: %i\n", annual_pop);
    }

   printf("Years: %i\n", year);

   return 0;

    // population = year_end

    //for (int year=0; annual_population == end_size ; year++  )

       // annual_population;
    // truncate
    //for (year_end == end_size)

    // llamas pass away each year
    // int annual_death = start_size/4


    // TODO: Print number of years
    // printf("Years: %s\n, year");
}
