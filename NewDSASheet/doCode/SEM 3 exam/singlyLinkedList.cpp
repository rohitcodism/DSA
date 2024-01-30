#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        this->head = nullptr;
    }

    bool isEmpty()
    {
        return this->head == nullptr;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Cannot display an empty Linked list" << endl;
            return;
        }
        Node *temp = this->head;
        cout<<"Linked list is: ";
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtBeginning(int val)
    {
        Node *temp = new Node(val);
        if (!temp)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        if(isEmpty()){
            this->head = temp;
            return;
        }
        temp->next = this->head;
        this->head = temp;
        Display();
    }

    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (!temp)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        if(isEmpty()){
            this->head = temp;
            return;
        }
        Node *curr = this->head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = temp;
        Display();
    }

    void insertAtPosition(int val, int pos)
    {
        Node *temp = new Node(val);
        if (!temp)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        if(isEmpty()){
            this->head = temp;
            return;
        }
        Node *curr = this->head;
        int count = 1;
        while(curr->next != nullptr && count < pos-1){
            curr = curr->next;
            count++;
        }
        temp->next = curr->next;
        curr->next = temp;
        Display();
    }

    void deleteAtBeginning()
    {
        if(isEmpty()){
            cout << "Cannot delete from an empty linked list" << endl;
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        Display();
    }

    void deleteAtEnd()
    {
        if(isEmpty()){
            cout << "Cannot delete from an empty linked list" << endl;
            return;
        }
        Node *curr = this->head;
        Node *prev = nullptr;
        while(curr->next != nullptr){
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
        Display();
    }

    void deleteAtPosition(int pos)
    {
        if(isEmpty()){
            cout << "Cannot delete from an empty linked list" << endl;
            return;
        }
        Node *curr = this->head;
        Node *prev = nullptr;
        int count = 1;
        while(curr->next != nullptr && count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        delete curr;
        Display();
    }

    void reverse()
    {
        if(isEmpty()){
            cout << "Cannot reverse an empty linked list" << endl;
            return;
        }
        Node *curr = this->head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        this->head = prev;
        Display();
    }

    void search(int val)
    {
        if(isEmpty()){
            cout << "Cannot search in an empty linked list" << endl;
            return;
        }
        Node *curr = this->head;
        int count = 1;
        while(curr != nullptr){
            if(curr->data == val){
                cout << "Element found at position " << count << endl;
                return;
            }
            curr = curr->next;
            count++;
        }
        cout << "Element not found" << endl;
    }

    void sort()
    {
        if(isEmpty()){
            cout << "Cannot sort an empty linked list" << endl;
            return;
        }
        Node *curr = this->head;
        Node *temp = nullptr;
        while(curr != nullptr){
            temp = curr->next;
            while(temp != nullptr){
                if(curr->data > temp->data){
                    int t = curr->data;
                    curr->data = temp->data;
                    temp->data = t;
                }
                temp = temp->next;
            }
            curr = curr->next;
        }
        Display();
    }
};

int main(){
    LinkedList l;

    int choice,val,pos;

    do
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete at beginning" << endl;
        cout << "5. Delete at end" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Reverse" << endl;
        cout << "8. Search" << endl;
        cout << "9. Sort" << endl;
        cout << "10. Display" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> val;
            l.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter the value to be inserted: ";
            cin >> val;
            l.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter the value to be inserted: ";
            cin >> val;
            cout << "Enter the position: ";
            cin >> pos;
            l.insertAtPosition(val,pos);
            break;
        case 4:
            l.deleteAtBeginning();
            break;
        case 5:
            l.deleteAtEnd();
            break;
        case 6:
            cout << "Enter the position: ";
            cin >> pos;
            l.deleteAtPosition(pos);
            break;
        case 7:
            l.reverse();
            break;
        case 8:
            cout << "Enter the value to be searched: ";
            cin >> val;
            l.search(val);
            break;
        case 9:
            l.sort();
            break;
        case 10:
            l.Display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
    
}