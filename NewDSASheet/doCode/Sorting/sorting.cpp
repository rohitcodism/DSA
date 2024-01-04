#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void display(int arr[], int n)
{
    cout << "All the array elements are : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        cout<<"i : "<<i<<endl;
        for (int j = 0; j < n - i - 1; j++)
        {
            cout<<"j : "<<j<<endl;
            cout<<"arr[j] : "<<arr[j]<<"  "<<"arr[j+1] : "<<arr[j+1]<<endl;
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    display(arr, n);
}

void modifiedBubbleSort(int arr[], int n){
    bool swapped;

    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        // if no swaps are made then the array is already sorted.
        if(!swapped)
            break;
    }
    display(arr, n);
}

int main()
{
    int n, x;
    cout << "Enter the length of the array : ";
    cin >> n;
    cout << endl;
    int a[n];
    cout << "Enter all the elements in the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    do
    {
        cout << "Enter your choice : \n1. Display the array\n2. Edit the array\n3. Bubble Sort\n4. Modified Bubble Sort"<<endl;
        cin >> x;
        cout << endl;
        switch(x)
        {
            case 1:
                display(a, n);
                break;
            case 2:
                cout << "Enter the length of the array : ";
                cin >> n;
                cout << endl;
                cout << "Enter all the elements in the array : " << endl;
                for (int i = 0; i < n; i++)
                {
                    cin >> a[i];
                }
                break;
            case 3:
                bubbleSort(a, n);
                break;
            case 4:
                modifiedBubbleSort(a,n);
                break;
            default:
                cout<<"Invalid choice try again!!!"<<endl;
                break;
        
        }
    } while (x!=0);
}