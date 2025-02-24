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
            front =newNode;
            rear=newNode;
            rear->next=front;
        }
        else{
        rear->next = newNode;
        rear = newNode;
        rear->next=front;
        }
    }

    void dequeue() 
    {
        if (front == NULL) 
        {
            return;
        }

        Node* temp = front;

        if (front == rear) 
        {
            rear=front= NULL;
        }
        else{
            front=front->next;
            rear->next=front;
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
        do 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp!=front);
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
