#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string letter);

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: \n");

    // Calling function
    int letter_length = count_letters(text);
    printf("%i letters\n", letter_length);

}

int count_letters(string letter)
{
    for (int i = 0; i < letter_length; i++)
        {
            if (isupper(letter) || islower(letter))
            {
                int letter_length = strlen(letter);
            }

            return letter_length;
        }

}