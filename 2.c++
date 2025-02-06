#include <iostream>
#define MAXSIZE 100
using namespace std;

struct STACK {
    int stArr[MAXSIZE];
    int top;
};

void create(STACK &s) {
    s.top = -1;
}

bool isFull(STACK &s) {
    return s.top == MAXSIZE - 1;
}

bool isEmpty(STACK &s) {
    return s.top == -1;
}

void push(STACK &s, int data) {
    if (isFull(s)) {
        cout << "Stack Overflow!\n";
        return;
    }
    s.stArr[++s.top] = data;
}

int pop(STACK &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    return s.stArr[s.top--];
}

int peek(STACK &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return s.stArr[s.top];
}

int main() {
    STACK s;
    create(s);
    int choice, data;

    do {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check Full\n5. Check Empty\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter data: "; cin >> data; push(s, data); break;
            case 2: cout << "Popped: " << pop(s) << endl; break;
            case 3: cout << "Top Element: " << peek(s) << endl; break;
            case 4: cout << (isFull(s) ? "Stack is full" : "Stack is not full") << endl; break;
            case 5: cout << (isEmpty(s) ? "Stack is empty" : "Stack is not empty") << endl; break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
