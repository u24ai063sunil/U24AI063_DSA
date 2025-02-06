#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = NULL; }

    bool isEmpty() { return top == NULL; }
    
    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        Node* temp = top;
        int data = top->data;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, data;

    do {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter data: "; cin >> data; s.push(data); break;
            case 2: cout << "Popped: " << s.pop() << endl; break;
            case 3: cout << "Top Element: " << s.peek() << endl; break;
            case 4: s.display(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
