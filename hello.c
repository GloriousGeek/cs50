#include <stdio.h>

int main(void)
{
    printf("hello world\n ");
}


int n;

do
{
    n = get_int("Height: \n")
}
while (n < 1 || n > 8);
