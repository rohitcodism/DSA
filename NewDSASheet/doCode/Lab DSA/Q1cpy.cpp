#include <iostream>
using namespace std;

class ArrayOperations
{
private:
    int *arr;
    int capacity;
    int size;

public:
    ArrayOperations(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
        // Initialize array with zeros
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = 0;
        }
    }

    void display()
    {
        cout << "Array : ";
        for (int i = 0; i < size; i++)
        {
            cout << this->arr[i] << endl;
        }
        cout << endl;
    }

    void takeInput()
    {
        cout << "Enter the elements of the array : ";
        for (int i = 0; i < capacity; i++)
        {
            cin >> arr[i];
            size++;
        }
        display();
    };

    void insertElement(int k, int x)
    {
        if (k >= 0 && k < capacity)
        {
            for (int i = size; i > k; i--)
            {
                cout<<arr[i]<<" "<<arr[i-1]<<endl;
                arr[i] = arr[i - 1];
            }
            arr[k] = x;
            size++;
        }
        else
        {
            cout << "Invalid position entered!!!" << endl;
        }
        display();
    }

    void updateElement(int oldOne, int newOne)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == oldOne)
            {
                arr[i] = newOne;
                cout << "Array updated." << endl;
                display();
                return;
            }
        }
        cout << "Element not found" << endl;
        display();
    }

    int searchElement(int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                cout << key << " was found at index : " << i << endl;
                return i;
            }
        }
        cout << "Element was not found in the array." << endl;
        return -1;
    }

    void removeElement(int key)
    {

        int index = searchElement(key);

        if (index != -1)
        {
            for (int i = index; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
        }
        else
        {
            cout << "Element is not in the array!!!" << endl;
        }
        display();
    }

    void getElement(int index)
    {
        if (index >= 0 && index < size)
        {
            cout << "The element at index : " << index << " is : " << arr[index] << endl;
        }
        else
        {
            cout << "Element not found!!!" << endl;
        }
    }
};

int main()
{
    // menu driven program
    int capacity;
    cout << "Enter the capacity of the array : ";
    cin >> capacity;
    ArrayOperations arr(capacity);
    int choice;

    do{
        cout << "1. Insert Element" << endl;
        cout << "2. Update Element" << endl;
        cout << "3. Search Element" << endl;
        cout << "4. Remove Element" << endl;
        cout << "5. Get Element" << endl;
        cout << "6. Display Array" << endl;
        cout<<"7. Take Input"<<endl; // added this option to take input from user
        cout << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            int k, x;
            cout << "Enter the position to insert the element : ";
            cin >> k;
            cout << "Enter the element to insert : ";
            cin >> x;
            arr.insertElement(k, x);
            break;
        case 2:
            int oldOne, newOne;
            cout << "Enter the element to update : ";
            cin >> oldOne;
            cout << "Enter the new element : ";
            cin >> newOne;
            arr.updateElement(oldOne, newOne);
            break;
        case 3:
            int key;
            cout << "Enter the element to search : ";
            cin >> key;
            arr.searchElement(key);
            break;
        case 4:
            int keyToRemove;
            cout << "Enter the element to remove : ";
            cin >> keyToRemove;
            arr.removeElement(keyToRemove);
            break;
        case 5:
            int index;
            cout << "Enter the index to get the element : ";
            cin >> index;
            arr.getElement(index);
            break;
        case 6:
            arr.display();
            break;
        case 7:
            arr.takeInput();
            break;
        }

    }while(choice);

    return 0;
}