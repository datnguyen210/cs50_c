#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100

typedef struct node {
    char* value;
    struct node* next;
} node;

node* hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

unsigned int hash(char* key)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % TABLE_SIZE;
}

void insert(char* word)
{
    unsigned int index = hash(word);
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->value = malloc(strlen(word) + 1);
    if (newNode->value == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->value, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

bool load(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if(file == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", fileName);
        return false;
    }
    char word[256];
    while(fscanf(file, "%255s", word) == 1)
    {
        insert(word);
    }
    fclose(file);
    return true;
}

int main(void)
{
    initializeTable();
    if(!load("dictionary.txt"))
    {
        fprintf(stderr, "Failed to load dictionary.\n");
        return 1;
    }
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        node* current = hashTable[i];
        while(current != NULL)
        {
            printf("Hash table at index %i is %s\n", i, current->value);
            // To print all values in the linked list within 1 hash index.
            current = current->next;
        }
    }
    return 0;
}
