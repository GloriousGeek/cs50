#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Declaring Functions
int count_letters(string letter);
int count_words(string word);
int count_sentences(string sentence);

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: ");

    // Calling function for letter
    int letter_count = count_letters(text);
    printf("%i letters\n", letter_count);

    // Word count function
    int word_count = count_words(text);
    printf("%i words\n", word_count);

    // Sentence count function
    int sentence_count = count_sentences(text);
    printf("%i sentences\n", sentence_count);

    // Coleman-Liau index formula

    //
    int L = (letter_count / word_count) * 100;

    //
    int S = (sentence_count / word_count) * 100;

    int index = 0.0588*L - 0.296*S - 15.8;
    printf("Grade %i\n", index);
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
int count_sentences(string sentence)
{
    // String length
    int length = strlen(sentence);

    // Variable to count sentences
    int sentence_count = 0;

    for (int i = 0; i < length; i++)
    {
        // Condition to indicate end of a sentence
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            // Updating sentence count
            sentence_count ++;
        }
    }

    // Returning sentence count value for non-void function
    return sentence_count;
}


