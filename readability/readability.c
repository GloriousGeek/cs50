#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Declaring Functions
int count_letters(string letter);
int count_words(string word);

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: ");

    // Calling function for letter
    int letter_length = count_letters(text);
    printf("%i letters\n", letter_length);

    // Word count function
    int word_count = count_words(text);
    printf("%i words\n", word_count);
}

// Letter count function
int count_letters(string letter)
{
    // Start counter by zero
    int letter_count = 0;

    // Calculate letter_length. it includes spaces, periods etc.
    int letter_length = strlen(letter);

    for (int i = 0; i < letter_length; i++)
        {
            // Check if the character is an alphabet
            if (isalpha(letter[i]))
            {
                // Only includes alphabets.
                letter_count ++;
            }
        }

        return letter_count;
}

// Defining word count function
int count_words(string word)
{
    // String length
    int length = strlen(word);

    // Starting a variable to count words
    int word_count = 0;

    for (int i = 0; i < length; i++)
    {
        // function argument is an alphabet and has a space
        if (isalpha(word[i]) && isspace(word[i]))
        {
            word_count ++;
        }

        return word_count;
    }
}