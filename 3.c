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

// Function to detect a loop in a linked list using Floyd’s Cycle Detection Algorithm
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // Loop detected
        }
    }

    return 0; // No loop
}

// Function to create a loop for testing
void createLoop(struct Node* head, int position) {
    if (position == 0) return;

    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    if (loopNode != NULL) {
        temp->next = loopNode; // Creating loop
    }
}

// Driver Code
int main() {
    struct Node* head = NULL;

    // Creating linked list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    // Creating a loop (pointing 50 -> 30)
    createLoop(head, 3);

    // Detect loop
    if (detectLoop(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop found in the linked list.\n");
    }

    return 0;
}
