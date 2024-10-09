//Write a C program to implement a Doubly linked list with Create and Display operation

#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node and insert it at the end of the doubly linked list
void create(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Update the last node's next and new node's previous pointers
    last->next = new_node;
    new_node->prev = last;
}

// Function to display the doubly linked list
void display(struct Node* node) {
    struct Node* last;
    printf("Forward traversal: \n");
    while (node != NULL) {
        printf("%d -> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");

    printf("Backward traversal: \n");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        create(&head, data);
    }

    printf("The doubly linked list is:\n");
    display(head);

    return 0;
}