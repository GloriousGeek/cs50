// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 130;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // node head. pointer to the first element of linked list
    // Make a copy of the head pointer and point to it
    // Check if value is in that node if not, keep moving

    // Obtain hash value of word
    int hash_value = hash(word);

    // Access linked list at that hash value index
    node *cursor = table[hash_value];


    // Look for word (strcasecmp)
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int length = strlen(word);

    // Initialize a variable to keep track of hash
    unsigned int v = 0;

    for(int i = 0; i < length; i++)
    {
        // Updating v
        v = (v << 2) ^ word[i];
    }

    if(v > N)
    {
        return v % N;
    }

    else
    {
        // Numerical index b/w 0 and N-1
        return toupper(word[0]) - 'A';
    }
}

// Initialize counter for words in dictionary to use in size function
int word_counter = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
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
        fscanf(file, "%s", w);

        // Allocate memory for new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload(); //
            return false;
        }

        // Copy the word into the node if malloc successful
        strcpy(n->word, w);

        // Insert (n) node into the hash table that returns index
        int h = hash(n->word);

        // Insert that word into the linked list
        // Add a new node to a linked list
        node *head = table[h];

        if (head == NULL)
        {
            // Point head to the new node (n)
            table[h] = n;
            word_counter++;
        }
        else
        {
            // Set new node's next pointer to be the first element in the linked list
            n->next = table[h];

            // Now, set head to be the new node that we created
            table[h] = n;
            word_counter++;
        }
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // From load function
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Call free on any memory allocated via malloc and return true

    node *cursor = table[];

    // Temperoray pointer to prevent the linked list from breaking
    void *tmp = cursor;

    // Iterate over hash table
    for(int i = 0; )
    return false;
}
