#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

class Solution
{
public:
    int getNthFromLast(struct Node *head, int n)
    {
        // Your code here
        int i, count, length, pos;
        struct Node *q = head;
        while (q)
        {
            q = q->next;
            count++;
        }
        length = count;
        pos = length - n;
        q = head;
        count = 0;
        while (count != pos)
        {
            q = q->next;
            count++;
        }
        return q->data;
    }
};

int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.getNthFromLast(head, k) << endl;
    }
    return 0;
}