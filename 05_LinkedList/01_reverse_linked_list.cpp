#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;          // value of the node
    ListNode *next;   // pointer to the next node

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to insert a new node at the end of the list
void insert(ListNode* &head, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

/*
 * Function: reverse
 * -----------------
 * Reverses a singly linked list.
 *
 * Time Complexity: O(n)  
 *   - Each node is visited exactly once.
 * Space Complexity: O(1)  
 *   - Only uses a few pointers (prev, curr, next).
 */
ListNode* reverse(ListNode* head) {
    ListNode *prev = nullptr;   // previous node (initially null)
    ListNode *curr = head;      // current node
    ListNode *next = nullptr;   // next node

    while (curr != nullptr) {
        next = curr->next;   // save next node
        curr->next = prev;   // reverse the pointer
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    return prev;  // new head of the reversed list
}

// Utility function to print the list
void printListNode(ListNode* head) {
    ListNode* temp = head;
    cout << "[";
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

int main() {
    ListNode* listNode = nullptr;

    // Insert values 1 to 5 into the list
    for (int i = 1; i <= 5; i++) {
        insert(listNode, i);
    }

    cout << "Original List: ";
    printListNode(listNode);

    // Reverse the list
    ListNode* rev = reverse(listNode);

    cout << "Reversed List: ";
    printListNode(rev);

    return 0;
}
