#include <bits/stdc++.h>
using namespace std;

void display(int a[], int n)
{

    cout << "The array elements are : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
}

void selectionSort(int a[], int n)
{

    for (int i = 0; i <= n - 2; i++)
    {
        int minIndex = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void bubbleSort(int a[], int n)
{

    for (int i = n - 1; i >= 1; i--)
    {
        bool swapped = false;
        for (int j = 0; j <= i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                bool swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    display(a, n);
}

void insertionSort(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (a[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (a[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[low], a[j]);

    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

int main()
{
    int arr[5] = {5, 9, 3, 1, 6};
    // selectionSort(arr,5);

    display(arr, 5);

    // bubbleSort(arr,5);

    // insertionSort(arr,5);

    quickSort(arr, 0, 5);

    display(arr, 5);
}