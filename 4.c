#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert at the beginning
void insertAtFirst(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert at the middle
void insertAtMiddle(struct Node** head, int new_data) {
    if (*head == NULL) {
        insertAtFirst(head, new_data);
        return;
    }

    struct Node *slow = *head, *fast = *head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = slow->prev;
    new_node->next = slow;

    if (slow->prev != NULL) {
        slow->prev->next = new_node;
    } else {
        *head = new_node;
    }

    slow->prev = new_node;
}

// Function to insert after a given node
void insertAfterNode(struct Node** head, int given_node, int new_data) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != given_node) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node %d not found!\n", given_node);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Driver function to test the implementation
int main() {
    struct Node* head = NULL;

    insertAtFirst(&head, 40);
    insertAtFirst(&head, 30);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 10);
    printf("Initial List: ");
    display(head);

    insertAtEnd(&head, 50);
    printf("After inserting at end: ");
    display(head);

    insertAtMiddle(&head, 25);
    printf("After inserting at middle: ");
    display(head);

    insertAfterNode(&head, 40, 60);
    printf("After inserting 60 after 40: ");
    display(head);

    return 0;
}
