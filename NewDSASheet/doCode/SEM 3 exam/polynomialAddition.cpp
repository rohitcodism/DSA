#include <iostream>
using namespace std;

// Node to represent a term in the polynomial expression
struct Node
{
    int coefficient;
    int exponent;
    Node *next;
    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

// Class to represent a polynomial expression using a linked list
class Polynomial
{
private:
    Node *head; // Pointer to the head of the linked list
public:
    // Constructor to initialize the polynomial with an empty list
    Polynomial() : head(nullptr) {}

    // Function to insert a new term into the polynomial expression
    void insertTerm(int coeff, int exp)
    {
        Node *newNode = new Node(coeff, exp);
        if (head == nullptr || exp > head->exponent)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr && current->next->exponent > exp)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to display the polynomial expression
    void display()
    {
        if (head == nullptr)
        {
            cout << "Polynomial is empty" << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->coefficient << "x^" << current->exponent;
            if (current->next != nullptr)
            {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Function to add two polynomial expressions
    Polynomial addPolynomials(Polynomial poly2)
    {
        Polynomial result;
        Node *current1 = this->head;
        Node *current2 = poly2.head;
        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->exponent == current2->exponent)
            {
                result.insertTerm(current1->coefficient + current2->coefficient, current1->exponent);
                current1 = current1->next;
                current2 = current2->next;
            }
            else if (current1->exponent > current2->exponent)
            {
                result.insertTerm(current1->coefficient, current1->exponent);
                current1 = current1->next;
            }
            else
            {
                result.insertTerm(current2->coefficient, current2->exponent);
                current2 = current2->next;
            }
        }
        while (current1 != nullptr)
        {
            result.insertTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        }
        while (current2 != nullptr)
        {
            result.insertTerm(current2->coefficient, current2->exponent);
            current2 = current2->next;
        }
        return result;
    }

    // Destructor to deallocate memory
    ~Polynomial()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    // Create first polynomial
    Polynomial poly1;
    poly1.insertTerm(5, 3); // 5x^3
    poly1.insertTerm(4, 2); // 4x^2
    poly1.insertTerm(2, 0); // 2x^0

    // Create second polynomial
    Polynomial poly2;
    poly2.insertTerm(3, 4); // 3x^4
    poly2.insertTerm(2, 3); // 2x^3
    poly2.insertTerm(1, 1); // 1x^1

    // Display the first polynomial
    cout << "Polynomial 1: ";
    poly1.display();

    // Display the second polynomial
    cout << "Polynomial 2: ";
    poly2.display();

    // Add the polynomials
    Polynomial sum = poly1.addPolynomials(poly2);

    // Display the sum of polynomials
    cout << "Sum of Polynomials: ";
    sum.display();

    return 0;
}
