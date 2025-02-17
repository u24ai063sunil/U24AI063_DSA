#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;

        if (position == 0 || head == NULL) {
            insertAtBeginning(data);
            return;
        }

        Node* temp = head;
        int count = 0;
        
        do {
            if (count == position - 1) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
            count++;
        } while (temp != head);

        cout << "Invalid position!" << endl;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position == 0) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        int count = 0;

        do {
            if (count == position) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
            count++;
        } while (temp != head);

        cout << "Invalid position!" << endl;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, data, position;

    while (true) {
        cout << "\n1. Insert at position\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete at position\n";
        cout << "5. Delete at beginning\n";
        cout << "6. Delete at end\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                cll.insertAtPosition(data, position);
                cll.display();
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                cll.insertAtBeginning(data);
                cll.display();
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cll.insertAtEnd(data);
                cll.display();
                break;
            case 4:
                cout << "Enter position: ";
                cin >> position;
                cll.deleteAtPosition(position);
                cll.display();
                break;
            case 5:
                cll.deleteAtBeginning();
                cll.display();
                break;
            case 6:
                cll.deleteAtEnd();
                cll.display();
                break;
            case 7:
                cll.display();
                break;
            case 0:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
