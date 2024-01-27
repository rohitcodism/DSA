#include <iostream>
using namespace std;

void Display(int A[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertHeap(int A[], int n)
{
    cout<<"Inside insert function"<<endl;
    int temp = A[n];
    int i = n;
    cout<<"Before while loop : "<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"A[i/2]: "<<A[i/2]<<endl;
    cout<<"A[i]: "<<A[i]<<endl;
    cout<<"temp: "<<temp<<endl;
    Display(A,n);
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
    cout<<"---------------"<<endl;
    cout<<"After while loop : "<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"temp: "<<temp<<endl;
    cout<<"A[i/2]: "<<A[i/2]<<endl;
    cout<<"A[i]: "<<A[i]<<endl;
    Display(A,n);
    cout<<"Exiting insert function"<<endl;
    cout<<"-------------------------------"<<endl;
}

void deleteElement(int A[], int n){
    int x,i,j;
    int x = A[n];

    A[1] = A[n];

    i = 1;
    j = i * 2;

    while(j = n-1){
        if(A[j+1]>A[j]){
            j = j+1;
        }

        if(A[i]<A[j]){
            swap(A[i], A[j]);
            i = j;
            j = 2*j;
        }else{
            break;
        }
    }
}

void createHeap(int a[], int length)
{
    for (int i = 2; i <= length; i++)
    {
        insertHeap(a, i);
    }
}

int main()
{

    // Taking input from the user of the length of the array
    int length;
    cout << "Enter the length of the array: ";
    cin >> length;
    cout << endl;

    // Creating an array of the given length
    int a[length];

    // Inserting elements into the array
    cout << "Enter the elements of the array: ";
    for (int i = 1; i <= length; i++)
    {
        cin >> a[i];
    }
    cout << endl;

    // Creating a heap from the array
    createHeap(a, length);

    // Displaying the heap
    cout << "The heap is: ";
    Display(a, length);
}