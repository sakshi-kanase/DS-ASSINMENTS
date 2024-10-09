// Write a C program to implement a Singly Circular linked list with following operations create(), display(), search(),length()

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a node and add it to the circular linked list
void create(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;
    
    // If the list is empty, make the new node as head and point it to itself
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
    } else {
        // Otherwise, traverse to the last node and update the last node's next
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
    }
}

// Function to display the circular linked list
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

// Function to search for an element in the list
void search(struct Node* head, int key) {
    struct Node* temp = head;
    int index = 0;
    int found = 0;
    
    if (head != NULL) {
        do {
            if (temp->data == key) {
                printf("Element %d found at index %d\n", key, index);
                found = 1;
                break;
            }
            temp = temp->next;
            index++;
        } while (temp != head);
        
        if (!found) {
            printf("Element %d not found in the list.\n", key);
        }
    } else {
        printf("The list is empty.\n");
    }
}

// Function to calculate the length of the circular linked list
int length(struct Node* head) {
    int len = 0;
    struct Node* temp = head;
    if (head != NULL) {
        do {
            len++;
            temp = temp->next;
        } while (temp != head);
    }
    return len;
}

int main() {
    struct Node* head = NULL;
    int n, data, key;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        create(&head, data);
    }
    
    printf("The circular linked list is: \n");
    display(head);
    
    printf("\nEnter an element to search: ");
    scanf("%d", &key);
    search(head, key);
    
    printf("\nLength of the circular linked list: %d\n", length(head));
    
    return 0;
}