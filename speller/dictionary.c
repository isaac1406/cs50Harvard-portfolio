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
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        puts("Error");
        return false;
    }
    // Read each word in the file
    char buffer[45];
    while(fscanf(source, "%s", buffer))
    {
        node *new = malloc(sizeof(node));
        int hashValue = hash(buffer);
        strcopy(new->word, buffer);
        new->next = table[hashValue];
        table[hashValue] = new;
    }

        // Add each word to the hash table

    // Close the dictionary file
    fclose(source);
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
