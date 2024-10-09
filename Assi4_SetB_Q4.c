// Write a C program to implement a Doubly Circular linked list with following operations create() and display(), append(),delete()

#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly circular linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node and insert it at the end of the doubly circular linked list
void create(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->next = new_node->prev = new_node;
        *head_ref = new_node;
    } else {
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;
    }
}

// Function to append a new node to the end of the doubly circular linked list
void append(struct Node** head_ref, int new_data) {
    create(head_ref, new_data);
}

// Function to delete a node in a doubly circular linked list
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Traverse until the key is found
    while (temp->data != key) {
        temp = temp->next;
        if (temp == *head_ref) {
            printf("Element %d not found in the list.\n", key);
            return;
        }
    }

    // If the list has only one node
    if (temp->next == temp && temp->prev == temp) {
        *head_ref = NULL;
        free(temp);
        return;
    }

    // If the node to be deleted is the head
    if (temp == *head_ref) {
        *head_ref = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    free(temp);
}

// Function to display the doubly circular linked list
void display(struct Node* head) {
    struct Node* temp = head;

    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("HEAD\n");
    } else {
        printf("The list is empty.\n");
    }
}

int main() {
    struct Node* head = NULL;
    int n, data, del_data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        create(&head, data);
    }

    printf("The doubly circular linked list is:\n");
    display(head);

    printf("\nEnter element to append: ");
    scanf("%d", &data);
    append(&head, data);
    printf("After append, the list is:\n");
    display(head);

    printf("\nEnter element to delete: ");
    scanf("%d", &del_data);
    deleteNode(&head, del_data);
    printf("After deletion, the list is:\n");
    display(head);

    return 0;
}