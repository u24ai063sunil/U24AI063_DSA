#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
}

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(struct Node* head) {
    struct Node *current = head, *prev = NULL;
    int hash[10000] = {0}; // Assuming values are within a reasonable range

    while (current != NULL) {
        if (hash[current->data]) {
            prev->next = current->next;
            free(current);
        } else {
            hash[current->data] = 1;
            prev = current;
        }
        current = prev->next;
    }
