// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // Allocate memory for new node
    node *n = malloc(sizeof(node));

    // Copy the word hello into n word element
    strcpy(n->word, "Hello");
    // Set next pointer (NULL if nothing comes after )
    n->next = NULL;

    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open Dictionary File
    FILE *file = fopen("dictionary.h", "r");
    if (file == NULL)
    {
        return false;
    }

    // Read strings from that file one at a time

    // int value;
    char w[LENGTH];
    while(fscanf(file, "%s", w) != EOF)
    {

        // char *
        fscanf(file, "%s", w);

        // Allocate memory for new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }

        // Copy the word into the node if malloc successful
        strcpy(n->word, w);

        // Insert (n) node into the hash table that returns index
        // To determine which linked list to use
        int h = hash(n->w);

        // Insert that word into the linked list
        // Add a new node to a linked list
        node *head = table[h];

        if (head == NULL)
        {
            table[h] = n;
            
        }


    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
