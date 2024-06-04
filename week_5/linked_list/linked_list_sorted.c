#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int main(int argc, char* argv[]) {
    Node* list = NULL;
    if(argc < 2){
        printf("Linked list creation failed: there's no value.");
    }

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        // Allocate a Node for the number
        Node* n = malloc(sizeof(Node));
        if(n == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        n->value = number;
        n->next = NULL;

        // Append the new node into current linked list
        if(list == NULL) {
            list = n;
        } 
        else if (n->value < list->value) {
            n->next = list;
            list = n;
        } 
        else {
            // Iterate over nodes in list
            for(Node* pointer = list; pointer != NULL; pointer = pointer->next) {
                if(pointer->next == NULL) {
                    pointer->next = n;
                    break;
                }

                if(n->value < pointer->next->value) {
                    n->next = pointer->next;
                    pointer->next = n;
                    break;
                }
            }
        }
    }

    Node* ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr->value);
        Node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}