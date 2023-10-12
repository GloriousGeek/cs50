#include <cs50.h>
#include <stdio.h>

int dynamic_Array[length];

int main(void)
{
    int length
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);


}

int dynamic_array[length]
{
    // Initial value of array should be 1
    int dynamic_array[0] = 1;

    for (i = 0; i < length, i++)
    {
        int dynamic_array[i] = 1;
        printf("%i\n", dynamic_array);

        dynamic_array *= 2;
    }
}