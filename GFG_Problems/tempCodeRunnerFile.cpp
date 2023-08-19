class Solution
{
public:
    int getNthFromLast(Node *head, int n)
    {
        // Your code here
        int i, count, length, pos;
        Node *q = head;
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