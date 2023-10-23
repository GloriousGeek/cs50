#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Defining data type candidate
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates_array[3];
    for (int i = 0; i < 3; i++)
    {
        candidates_array[i] = get_candidate("Enter Candidates\n");
    }
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);


    candidate c;
    string name = get_string("Name: ");
    c.name = name;

    int votes = get_int("Votes: ");
    c.votes = votes;

    return c;
}

