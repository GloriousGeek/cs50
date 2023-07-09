#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int counter = 3;

    // incrementing variable counter by 1
    // counter = counter + 1;

    // or same increment with better syntax (syntaxtic sugar)
    // adding one to a variable can also be done as counter++;
    // counter += 1;

    // if single variable, we can call int i, char c etc:
    int i = 3;

    // loops can use boolean expressions in paranthesis
    while (i > 0)
    {
        printf("meow\n");
        i -= 1;
    }
}