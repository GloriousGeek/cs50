// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 143000;

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

    for (int i = 0; i < length; i++)
    {
        // Updating v
        v += tolower(word[i]);
        // v = (v << 2) ^ word[i];
    }

    // Numerical index b/w 0 and N-1
    return v % N;
}

// Initialize counter for words in dictionary to use in size function
int word_counter = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open Dictionary File
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Read strings from that file one at a time

    // Buffer to store each word with max limit;
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy the word into the node/buffer if malloc successful
        strcpy(n->word, word);

        // Hash word to obtain hash value
        int hash_value = hash(n->word);

        // Insert node into hash table at that location
        // Add a new node to a linked list
        node *head = table[hash_value];

        if (head == NULL)
        {
            // Point head to the new node (n)
            table[hash_value] = n;
            word_counter++;
        }
        else
        {
            // Set new node's next pointer to be the first element in the linked list
            n->next = table[hash_value];

            // Now, set head to be the new node that we created
            table[hash_value] = n;
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
    // Iterate over each element in the hash table
    for (int i = 0; i < N; i++)
    {
        // table[i] = NULL;
        // Cursor to point at the address of the first node
        // Cursor will point to the linked list while freeing to avoid breaking the linked list
        node *cursor = table[i];

        // Iterate over the linked list for the current hash value
        while (cursor != NULL)
        {
            // Temp pointer to free memory
            node *tmp = cursor;

            // Point cursor to the next elemenet before freeing
            cursor = cursor->next;

            // Free tmp
            free(tmp);
        }
        // if (cursor == NULL && i == N -1)
        // {
        //     return true;
        // }

    }

    return true;
}
