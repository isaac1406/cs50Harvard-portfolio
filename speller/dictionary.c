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

// initialize global variables
int numWords = 0;
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashValue = hash(word);
    node *cursor = table[hashValue];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
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
        // Add each word to the hash table
        strcopy(new->word, buffer);
        new->next = table[hashValue];
        table[hashValue] = new;
        numWords++;
    }
    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // global variable counted in load function
    return numWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //
    for (int i = 0; i < N; i++)
    {
        
    }
    return false;
}
