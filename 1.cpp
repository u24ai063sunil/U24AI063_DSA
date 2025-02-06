#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;
public:
    CircularLinkedList() { last = NULL; }

    void insertAtPosition(int data, int pos);
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void deleteAtPosition(int pos);
    void deleteFirst();
    void deleteLast();
    void display();
};

void CircularLinkedList::insertAtPosition(int data, int pos) {
    Node* newNode = new Node();
    newNode->data = data;
    
    if (!last) {
        newNode->next = newNode;
        last = newNode;
        return;
    }

    Node* temp = last->next;
    for (int i = 1; i < pos - 1 && temp->next != last->next; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) last = newNode;
}

void CircularLinkedList::insertAtBeginning(int data) {
    insertAtPosition(data, 1);
}

void CircularLinkedList::insertAtEnd(int data) {
    insertAtPosition(data, (last ? 2 : 1));
}

void CircularLinkedList::deleteAtPosition(int pos) {
    if (!last) return;

    Node *temp = last->next, *prev = last;
    if (pos == 1) {
        if (last->next == last) {
            delete last;
            last = NULL;
            return;
        }
        last->next = temp->next;
        delete temp;
        return;
    }

    for (int i = 1; temp != last && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == last) last = prev;
    prev->next = temp->next;
    delete temp;
}

void CircularLinkedList::deleteFirst() {
    deleteAtPosition(1);
}

void CircularLinkedList::deleteLast() {
    if (!last) return;

    Node* temp = last->next, *prev = last;
    while (temp->next != last->next) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == last) last = NULL;
    else prev->next = last->next;

    delete temp;
}

void CircularLinkedList::display() {
    if (!last) return;

    Node* temp = last->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

int main() {
    CircularLinkedList cll;
    int choice, data, pos;

    do {
        cout << "1. Insert at position\n2. Insert at beginning\n3. Insert at end\n4. Delete at position\n5. Delete first\n6. Delete last\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter data & position: "; cin >> data >> pos; cll.insertAtPosition(data, pos); break;
            case 2: cout << "Enter data: "; cin >> data; cll.insertAtBeginning(data); break;
            case 3: cout << "Enter data: "; cin >> data; cll.insertAtEnd(data); break;
            case 4: cout << "Enter position: "; cin >> pos; cll.deleteAtPosition(pos); break;
            case 5: cll.deleteFirst(); break;
            case 6: cll.deleteLast(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
        cll.display();
    } while (choice != 0);

    return 0;
}
