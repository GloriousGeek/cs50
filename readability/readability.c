#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string letter);

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: ");

    // Calling function
    int letter_length = count_letters(text);
    printf("%i letters\n", letter_length);

}

int count_letters(string letter)
{
    // Start counter by zero
    int letter_count = 0;

    // Calculate letter_length
    int letter_length = strlen(letter);

    for (int i = 0; i < letter_length; i++)
        {
            if (isalpha(letter[i]) || isupper(letter[i]) || islower(letter[i]))
            {
                letter_count ++;
            }
        }
        
        return letter_count;
}