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
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Hash Value
unsigned int hash_value = 0;

// Total Word Counter
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // get hash value
    hash_value = hash(word);

    // point cursor to array index
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        // compare word to current node word
        if (strcasecmp(cursor->word, word))
        {
            return true;
        }
        // point to the next node if not found
        else
        {
            cursor = cursor->next;
        }
    }

    // if not found
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
    // TODO
    // Open Dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Failed to open file: %s\n", dictionary);
        return false;
    }
    // Read file
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // create new node for new word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Failed to allocate memory for word: %s\n", word);
            return false;
        }

        // copy current word into new node
        strcpy(new_node->word, word);

        // get hash of word
        hash_value = hash(word);

        // insert new node to hash table
        new_node->next = table[hash_value];
        table[hash_value] = new_node;

        // total word counter
        word_count++;
    }
    // close file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor;
    node *temp;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    if (table == NULL)
    {
        return true;
    }
    return false;
}
