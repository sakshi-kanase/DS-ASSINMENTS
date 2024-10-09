//Write a C program to implement a Doubly linked list with following operations create() , display(), insert(),delete()

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

// Function to insert a node after a given previous node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }

    prev_node->next = new_node;
}

// Function to delete a node in a doubly linked list
void deleteNode(struct Node** head_ref, struct Node* del_node) {
    if (*head_ref == NULL || del_node == NULL) {
        return;
    }

    // If the node to be deleted is the head node
    if (*head_ref == del_node) {
        *head_ref = del_node->next;
    }

    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }

    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }

    free(del_node);
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
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data, del_data;
    struct Node* temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        create(&head, data);
    }

    printf("The doubly linked list is:\n");
    display(head);

    printf("Enter data of node to delete: ");
    scanf("%d", &del_data);

    // Find the node to delete
    temp = head;
    while (temp != NULL && temp->data != del_data) {
        temp = temp->next;
    }

    // Delete the node if found
    if (temp != NULL) {
        deleteNode(&head, temp);
        printf("After deletion, the list is:\n");
        display(head);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}