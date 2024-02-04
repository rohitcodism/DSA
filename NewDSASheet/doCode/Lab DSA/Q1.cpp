#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int *arr;
    int size;
public:
    ArrayOperations(int n) {
        size = n;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0; // Initialize array with zeros
    }

    ~ArrayOperations() {
        delete[] arr;
    }

    void updateElement(int k, int x) {
        if (k >= 0 && k < size)
            arr[k] = x;
        else
            cout << "Invalid position!" << endl;
    }

    void insertElement(int k, int x) {
        if (k >= 0 && k < size) {
            for (int i = size - 1; i > k; i--)
                arr[i] = arr[i - 1];
            arr[k] = x;
            size++;
        } else
            cout << "Invalid position!" << endl;
    }

    int searchElement(int x) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == x)
                return i;
        }
        return -1; // Element not found
    }

    void removeElement(int x) {
        int index = searchElement(x);
        if (index != -1) {
            for (int i = index; i < size - 1; i++)
                arr[i] = arr[i + 1];
            size--;
        } else
            cout << "Element not found!" << endl;
    }

    int getElement(int k) {
        if (k >= 0 && k < size)
            return arr[k];
        else {
            cout << "Invalid position!" << endl;
            return -1;
        }
    }

    void displayArray() {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    ArrayOperations array(n);

    int choice, k, x;
    char repeat;
    do {
        cout << "\nMenu:\n";
        cout << "1. Update an element at position k\n";
        cout << "2. Insert an element at position k\n";
        cout << "3. Search an element in the array\n";
        cout << "4. Remove an element from the array\n";
        cout << "5. Display an element from the array\n";
        cout << "6. Display the whole array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position (k) and element (x) to update: ";
                cin >> k >> x;
                array.updateElement(k, x);
                break;
            case 2:
                cout << "Enter position (k) and element (x) to insert: ";
                cin >> k >> x;
                array.insertElement(k, x);
                break;
            case 3:
                cout << "Enter the element to search: ";
                cin >> x;
                k = array.searchElement(x);
                if (k != -1)
                    cout << "Element found at position " << k << endl;
                else
                    cout << "Element not found!" << endl;
                break;
            case 4:
                cout << "Enter the element to remove: ";
                cin >> x;
                array.removeElement(x);
                break;
            case 5:
                cout << "Enter position (k) to display: ";
                cin >> k;
                x = array.getElement(k);
                if (x != -1)
                    cout << "Element at position " << k << " is " << x << endl;
                break;
            case 6:
                array.displayArray();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice);

    return 0;
}
