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

// Function to rotate the linked list counterclockwise by k nodes
void rotateList(struct Node** head, int k) {
    if (*head == NULL || k == 0) return;

    // Find the length of the linked list
    struct Node* temp = *head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Effective rotation
    k = k % length;
    if (k == 0) return;

    // Traverse to the k-th node
    temp = *head;
    for (int i = 1; i < k; i++)
        temp = temp->next;

    // Update links
    struct Node* newHead = temp->next;
    temp->next = NULL;

    struct Node* temp2 = newHead;
    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = *head;
    *head = newHead;
}

// Function to print the linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver Code
int main() {
    struct Node* head = NULL;
    
    // Creating linked list 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    printf("Original List: ");
    display(head);

    int k = 2; // Rotate by k nodes
    rotateList(&head, k);

    printf("Rotated List (by %d): ", k);
    display(head);

    return 0;
}
