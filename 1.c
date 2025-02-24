#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;


Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}


int isEmpty(Node* front) {
    return front == NULL;
}


int isFull() {
    return 0;
}


void enqueue(Node** front, int data, int priority) {
    Node* newNode = createNode(data, priority);


    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue(Node** front) {
    if (isEmpty(*front)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = *front;
    *front = temp->next;
    free(temp);
}


int peek(Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}


void display(Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue: ");
    Node* temp = front;
    while (temp != NULL) {
        printf("(%d, P%d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* front = NULL;

    printf("*****************Priority Queue operations *****************\n");

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. isFull\n");
    printf("5. isEmpty\n");
    printf("6. Display\n");
    printf("7. Exit\n");

    int choice, data,priority;
    
    while (true) 
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                printf("Enter priority: ");
                scanf("%d",&priority);
                enqueue(&front,data,priority);
                display(front);
                break;

            case 2:
                dequeue(&front);
                display(front);
                break;
            
            case 3:
                printf("Front element: %d\n",peek(front));
                break;

            case 4:
                printf("Queue is full: %d\n",isFull());
                break;

            case 5:
                printf("Queue is empty: %d\n",isEmpty(front));
                break;

            case 6:
                display(front);
                break;

            case 7:
                printf("Exiting...");
                exit(0);        

            default:
                printf("Invalid choice\n");
        }
    }
}
    
