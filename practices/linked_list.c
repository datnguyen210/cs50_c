#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next; // *next is the POINTER to the next Node.
} Node;

int main(int argc, char *argv[])
{
    Node* list = NULL;
    for (int i = argc - 1; i > 0; i--)
    {
        int number = atoi(argv[i]);
        
        Node* n = malloc(sizeof(Node));
        if(n == NULL)
        {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        n->number = number;
        n->next = list;
        list = n;
    }

    // Print the whole list
    Node* pointer = list;
    while(pointer != NULL)
    {
        printf("%i\n", pointer->number);
        Node* temp = pointer;
        pointer = pointer->next;
        free(temp);
    }
}