// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    hash_value = hash(word);
    node *cursor = table[hash_value];
    while (cursor->next != NULL)
    {
        if (strcmp(head->word, word))
        {
            return true;
        }
        else
        {
            cursor = cursor->next
        }
    }
    return false;
    // set cursor to root
    node *cursor = root;

    // iterate through every letter of word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = tolower(word[i]) - 'a';
        // if current node is not NULL
        if (cursor->children[index] != NULL)
        {
            // point the cursor to the next node
            cursor = cursor->children[index];
        }
        if (cursor->is_word)
        {
            return true;
        }
    }
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
        return false;
    }
    // Read file
    char word[N + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // create new node for new word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
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
    return true;
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
