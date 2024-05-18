#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* curr = dummyHead;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        } else {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }
    }

    if (list1) {
        while (list1) {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        }
    }
    if (list2) {
        while (list2) {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }
    }

    ListNode* Result = dummyHead->next;
    delete dummyHead;
    return Result;
}

// Function to partition and merge lists recursively
ListNode* PartitionAndMerge(vector<ListNode*>& lists, int s, int e) {
    if (s == e) {
        return lists[s];
    }

    int mid = s + (e - s) / 2;

    ListNode* L1 = PartitionAndMerge(lists, s, mid);
    ListNode* L2 = PartitionAndMerge(lists, mid+1, e);

    ListNode* L = mergeTwoLists(L1, L2);

    return L;
}

// Function to merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    int s = 0;
    int e = k - 1;

    return PartitionAndMerge(lists, s, e);
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    // Create three sorted linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    // Store lists in a vector
    vector<ListNode*> lists = {list1, list2, list3};

    // Merge the sorted lists
    ListNode* mergedList = mergeKLists(lists);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory
    delete list1;
    delete list2;
    delete list3;

    // Delete merged list nodes
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
