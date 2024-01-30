
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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void insertHeap(int A[], int n)
{
    int temp = A[n];
    int i = n;
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
void createHeap(int a[], int length)
{
    for (int i = 2; i <= length; i++)
    {
        insertHeap(a, i);
    }
}

int deleteElement(int A[], int n)
{
    int x, i, j, val;
    x = A[n];

    val = A[1];

    A[1] = A[n];

    i = 1;
    j = i * 2;

    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
        {
            j = j + 1;
        }

        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    A[n] = val;
    return val;
}

void heapify(int A[], int n){
    int temp = A[n];
    int i = n;

    while(i>1 && (temp > A[i*2] || temp > A[i*2+1] )){
        if(A[i*2+1] > A[i*2]){
            A[i] = A[i*2+1];
            i = i*2+1;
        }
        else{
            A[i] = A[i*2];
            i = i*2;
        }
        i--;
    }
    A[i] = temp;
}

int main()
{
    /* The code snippet initializes an array `H` with the values `{0, 10, 20, 30, 25, 5, 40, 35}`. This
    array represents a heap data structure. The comment `// after inserting the elements in the heap:
    40,25,35,10,5,20,30` indicates the expected order of the elements in the heap after inserting them. */

    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    //** after inserting the elements in the heap: 40,25,35,10,5,20,30

    /* The code snippet is inserting elements into the heap. It starts from index 2 and iterates up to
    index 7 (inclusive). For each index, it calls the `insertHeap` function to insert the element at
    that index into the heap. After inserting all the elements, it displays the heap by calling the
    `Display` function. */
    // inserting elements into the heap and creating a heap
    //TODO: time complexity: O(nlogn)

    // for (int i = 2; i <= 7; i++)
    // {
    //     insertHeap(H, i);
    // }

    // cout << "The heap is: ";
    // Display(H, 7);

    /* The code is deleting an element from the heap and then displaying the updated heap. */

    //** after deleting the element from the heap: 35,25,30,10,5,20
    //TODO: time complexity: O(logn)

    // cout << "After deleting the deleted element from the heap is: " << deleteElement(H, 7) << endl;

    // cout << "After deletion the heap is: ";
    // Display(H, 7);
    // cout << endl;

    /* The code snippet is performing heap sort on the given heap. It starts from the last element of the
    heap and repeatedly deletes the root element (which is the maximum element in a max heap) and places
    it at the end of the array. This process is repeated until all elements are sorted in ascending
    order. Finally, it displays the sorted heap. */

    // //** Heap sort
    // //TODO: time complexity: O(nlogn)
    // for (int i = 7; i > 1; i--)
    // {
    //     deleteElement(H, i);
    // }

    // cout << "After sorting the heap is: ";
    // Display(H, 7);

    // Heapify
    heapify(H,7);
    cout << "After heapify the heap is: ";
    Display(H, 7);

    return 0;
}