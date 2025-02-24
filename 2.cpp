/*
Implement a queue using a linked list with two pointers: front and rear. 
Elements can only be inserted via the rear pointer and deleted via the front pointer.
The queue has the following basic operations:
• enqueue() – Insert an element in the queue.
• dequeue() – Remove the element from the queue.
• peek() – Return the element at the front node of the queue
• isFull() – Validates if the queue is full or not.
• isEmpty() – Checks if the queue is empty.
*/

#include <iostream>

using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
};

class Queue 
{
    public:
    Node* front;
    Node* rear;

    
    Queue() 
    {
        front = rear = NULL;
    }

    void enqueue(int data) 
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (rear == NULL) 
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() 
    {
        if (front == NULL) 
        {
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) 
        {
            rear = NULL;
        }

        delete temp;
    }

    int peek() 
    {
        if (front == NULL) 
        {
            return -1;
        }

        return front->data;
    }

    bool isFull() 
    {
        Node* temp = new Node();
        if (temp == NULL) 
        {
            return true;
        }

        delete temp;
        return false;
    }
    bool isEmpty() 
    {
        return front == NULL;
    }

    void display() 
    {
        Node* temp = front;
        while (temp != NULL) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main()
{
    Queue q;
    cout << "***************** Queue operations *****************" << endl;

    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. isFull" << endl;
    cout << "5. isEmpty" << endl;
    cout << "6. Display" << endl;
    cout << "7. Exit" << endl;

    int choice, data;
    
    while (true) 
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                q.enqueue(data);
                q.display();
                break;

            case 2:
                q.dequeue();
                q.display();
                break;
            
            case 3:
                cout << "Front element: " << q.peek() << endl;
                break;

            case 4:
                cout << "Queue is full: " << q.isFull() << endl;
                break;

            case 5:
                cout << "Queue is empty: " << q.isEmpty() << endl;
                break;

            case 6:
                q.display();
                break;

            case 7:
                cout << "Exiting..." << endl;
                exit(0);        

            default:
                cout << "Invalid choice" << endl;
        }
    }
}
