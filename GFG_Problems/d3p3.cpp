//{ Driver Code Starts
#include <iostream>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int temp, i;
        Node *q, *p;
        q = head;
        p = q->next;
        while(q){
            while(p){
                if(p->data<q->data){
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                    p = p->next;
                }else{
                    p = p->next;
                }
            }
            q = q->next;
        }
        return head;
    }





int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends