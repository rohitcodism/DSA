#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
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
    for (int i = 0; i < n - 1; i++)
    {
        cout << "i : " << i << endl;
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "j : " << j << endl;
            cout << "arr[j] : " << arr[j] << "  "
                << "arr[j+1] : " << arr[j + 1] << endl;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    display(arr, n);
}

void modifiedBubbleSort(int arr[], int n)
{
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // if no swaps are made then the array is already sorted.
        if (!swapped)
            break;
    }
    display(arr, n);
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    display(arr, n);
}

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int B[100];
    i = low;
    j = mid + 1;
    k = low;

    cout << "Merging sub-arrays: ";
    for (int t = low; t <= high; ++t)
    {
        cout << arr[t] << " ";
    }
    cout << endl;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k++] = arr[i++];
        }
        else
        {
            B[k++] = arr[j++];
        }
    }

    cout << "After comparing and merging: ";
    for (int t = low; t <= high; ++t)
    {
        cout << B[t] << " ";
    }
    cout << endl;

    while (i <= mid)
    {
        B[k++] = arr[i++];
    }
    while (j <= high)
    {
        B[k++] = arr[j++];
    }

    cout << "After copying remaining elements from left and right sub-arrays: ";
    for (int t = low; t <= high; ++t)
    {
        cout << B[t] << " ";
    }
    cout << endl;

    for (i = low; i <= high; ++i)
    {
        arr[i] = B[i];
    }

    cout << "After copying back to the original array: ";
    for (int t = low; t <= high; ++t)
    {
        cout << arr[t] << " ";
    }
    cout << endl;
    cout << "--------------------------------------" << endl;
}

void mergeSort(int A[], int n)
{
    int p, i, low, mid, high;

    for (p = 2; p <= n; p = p * 2)
    {
        cout << "\nIteration with p = " << p << ":\n";
        for (i = 0; i + p - 1 < n; i += p)
        {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;

            cout << "Low : " << low << "\n"
                << "Mid : " << mid << "\n"
                << "High : " << high << "\n";

            merge(A, low, mid, high);
        }
    }
    if (p/2 < n)
    {
        cout << "Inside if block\n";
        display(A, n);
        cout << "p/2 : " << p / 2 << endl;
        cout << "n-1 : " << n - 1 << endl;
        cout << "If block over\n";
        merge(A, 0, p / 2, n - 1);
    }
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
        cout << "Enter your choice : \n1. Display the array\n2. Edit the array\n3. Bubble Sort\n4. Modified Bubble Sort\n5. Selection Sort\n6. Merge Sort" << endl;
        cin >> x;
        cout << endl;
        switch (x)
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
            modifiedBubbleSort(a, n);
            break;
        case 5:
            selectionSort(a, n);
            break;
        case 6:
            mergeSort(a, n);
            break;
        default:
            cout << "Invalid choice try again!!!" << endl;
            break;
        }
    } while (x != 0);
}