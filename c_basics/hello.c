#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting input and returning it with greeting
    string answer = get_string("What is your name?\n");
    printf("hello, %s\n", answer);
}

// To complie write in terminal (make hello)
// To run write in terminal (./hello)
