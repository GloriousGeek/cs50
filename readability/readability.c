#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Declaring Functions
int count_letters(string letter);
int count_words(string word);
int count_senteces(string sentence);

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

    // Starting a variable to count words from 1 because space(isspace) does not count the last word
    int word_count = 1;

    for (int i = 0; i < length; i++)
    {
        // function argument is an alphabet and has a space
        if (isspace(word[i]))
        {
            word_count ++;
        }
    }

    // Returning a value for the non-void function
    return word_count;
}

// Defining sentence count function
int count_senteces(string sentence)
{
    // String length
    int length = strlen(sentence);

    // Variable to count sentences
    int sentence_count = 0;

    for (int i = 0; i < length; i++)
    {
        if (sentence == ')
    }
}