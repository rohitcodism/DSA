// implementation of the Polynomial expression using linked list

#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    Node *next;
    Node(int coeff, int exp)
    {
        this->coeff = coeff;
        this->exp = exp;
        this->next = nullptr;
    }
};

class Polynomial
{
private:
    Node *head;
public:
    Polynomial()
    {
        this->head = nullptr;
    }

    bool underflow()
    {
        return this->head == nullptr;
    }

    void display()
    {
        if (underflow())
        {
            cout << "Cannot display an empty Linked list" << endl;
            return;
        }
        Node *temp = this->head;
        cout << "Polynomial is: " << endl;
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->exp << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push(int coeff, int exp)
    {
        Node *temp = new Node(coeff, exp);

        if (!temp)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        temp->next = this->head;
        this->head = temp;
    }

    void pop()
    {
        if (underflow())
        {
            cout << "Heap Underflow" << endl;
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    void evaluate(int x)
    {
        if (underflow())
        {
            cout << "Heap Underflow" << endl;
            return;
        }
        Node *temp = this->head;
        int sum = 0;
        while (temp != NULL)
        {
            sum += temp->coeff * pow(x, temp->exp);
            temp = temp->next;
        }
        cout << "Polynomial evaluated at x = " << x << " is: " << sum << endl;
    }
};

int main()
{
    Polynomial p;
    p.push(1, 2);
    p.push(2, 1);
    p.push(3, 0);
    p.display();
    p.evaluate(2);
    return 0;
}