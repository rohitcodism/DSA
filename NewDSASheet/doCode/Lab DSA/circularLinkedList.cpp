// implementation of circular linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = NULL;
    }

    void display() {
        Node* temp = head;
        if (head != NULL) {
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
        }
        cout << endl;
    }

    void insertAtBegin(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
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

    void deleteAtBegin() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            Node* prev = NULL;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }
};

// menu driven program
int main() {
    CircularLinkedList list;
    int choice, data;
    while (1) {
        cout << "1. Insert at begin" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete at begin" << endl;
        cout << "4. Delete at end" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtBegin(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                list.deleteAtBegin();
                break;
            case 4:
                list.deleteAtEnd();
                break;
            case 5:
                list.display();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}