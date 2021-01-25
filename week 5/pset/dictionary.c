#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int N = 26;
unsigned int hashed;
unsigned int count;
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hashed = hash(word);
    node *tempNode = table[hashed];
    while (tempNode != NULL)
    {
        if (strcasecmp(word, tempNode->word) == 0)
        {
            return true;
        }
        tempNode = tempNode->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        hashed = hash(word);
        n->next = table[hashed];
        table[hashed] = n;
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (count > 0)
    {
        return count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tempNode = table[i];
        while (tempNode)
        {
            node *tmp = tempNode;
            tempNode = tempNode->next;
            free(tmp);
        }
        if (i == N - 1 && tempNode == NULL)
        {
            return true;
        }
    }
    return false;
}
