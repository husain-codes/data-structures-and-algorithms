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

// Function to make the list cyclic by connecting last node to `pos`th node (0-based index)
void make_cyclic(ListNode* &head , int pos) {
    if (!head) return; // empty list
    ListNode* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    ListNode* curr = head;
    for (int i = 0; i < pos && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr) last->next = curr;  // connect only if pos is valid
}

/**
 * Detect if a linked list has a cycle using Floyd’s Tortoise and Hare.
 * 
 * Time Complexity: O(n) 
 *    - Each node is visited at most twice (once by slow, once by fast).
 * Space Complexity: O(1) 
 *    - Only two pointers are used.
 */
bool isCyclic(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // move slow by 1
        fast = fast->next->next;   // move fast by 2
        if (slow == fast) return true; // cycle detected
    }
    return false; // fast reached end => no cycle
}

int main() {
    // -------- Edge Case 1: Empty list --------
    ListNode* empty = nullptr;
    cout << "Empty list -> " << isCyclic(empty) << endl; // Expected: 0

    // -------- Edge Case 2: Single node no cycle --------
    ListNode* single = nullptr;
    insert(single, 10);
    cout << "Single node (no cycle) -> " << isCyclic(single) << endl; // Expected: 0

    // -------- Edge Case 3: Single node with cycle --------
    ListNode* self_cycle = new ListNode(1);
    self_cycle->next = self_cycle; // node points to itself
    cout << "Single node (self cycle) -> " << isCyclic(self_cycle) << endl; // Expected: 1

    // -------- Example Case: 3 -> 2 -> 0 -> -4, with cycle at node 2 --------
    ListNode* cyclic = nullptr;
    insert(cyclic, 3);
    insert(cyclic, 2);
    insert(cyclic, 0);
    insert(cyclic, -4);
    make_cyclic(cyclic, 1); // connect last node to index 1 (value=2)
    cout << "List with cycle -> " << isCyclic(cyclic) << endl; // Expected: 1

    // -------- Example Case: 1 -> 2 -> 3 -> 4 (no cycle) --------
    ListNode* noCycle = nullptr;
    insert(noCycle, 1);
    insert(noCycle, 2);
    insert(noCycle, 3);
    insert(noCycle, 4);
    cout << "List without cycle -> " << isCyclic(noCycle) << endl; // Expected: 0

    return 0;
}
