#include <cs50.h>
#include <stdio.h>

int count_letters(letter);

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: \n");
}

int count_letters(string letter)
{
    if (isalpha(letter) || isupper(letter) || islower(letter))
    {
        int letter_length = strlen(letter);

        for (int i = 0; i < letter_length; i++)
        {
            
        }
    }
}