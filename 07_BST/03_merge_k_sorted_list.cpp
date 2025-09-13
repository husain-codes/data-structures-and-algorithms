#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Function: mergeKLists
 * ----------------------
 * Merges k sorted linked lists into a single sorted linked list.
 *
 * Approach:
 * 1. Push all node values into a min-heap (priority_queue with greater comparator).
 * 2. Pop from heap one by one and create new nodes linked together.
 *
 * Time Complexity: O(N log N)
 *  - N = total number of nodes in all lists
 *  - Each push/pop in heap is O(log N)
 *
 * Space Complexity: O(N)
 *  - Heap stores all node values
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int , vector<int> , greater<int>> mheap;

    // Push all values from all lists into heap
    for (int i = 0; i < lists.size(); i++) {
        ListNode* temp = lists[i];
        while(temp != nullptr) {
            mheap.push(temp->val);
            temp = temp->next;
        }
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    // Build merged list from heap
    while(!mheap.empty()){
        ListNode* temp = new ListNode(mheap.top());
        mheap.pop();
        if(!head) {
            head = tail = temp; // first node
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

/**
 * Helper function: insert
 * -----------------------
 * Inserts a value at the end of a linked list
 */
void insert(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if(!head) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

/**
 * Helper function: printList
 * --------------------------
 * Prints all values in a linked list
 */
void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first linked list: 1 -> 4 -> 5
    ListNode* l1 = nullptr;
    insert(l1, 1);
    insert(l1, 4);
    insert(l1, 5);

    // Create second linked list: 1 -> 3 -> 4
    ListNode* l2 = nullptr;
    insert(l2, 1);
    insert(l2, 3);
    insert(l2, 4);

    // Create third linked list: 2 -> 6
    ListNode* l3 = nullptr;
    insert(l3, 2);
    insert(l3, 6);

    // Merge all lists
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* mergedHead = mergeKLists(lists);

    // Print merged linked list
    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}
