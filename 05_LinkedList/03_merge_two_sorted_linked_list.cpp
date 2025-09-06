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

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/**
 * Merge two sorted linked lists into one sorted list
 * 
 * Time Complexity: O(m + n)   (where m, n are lengths of the lists)
 * Space Complexity: O(1)      (we only rearrange pointers, no extra space)
 */
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    // Pick the smaller head to start merged list
    ListNode* merge = nullptr;
    if (list1->val <= list2->val) {
        merge = list1;
        list1 = list1->next;
    } else {
        merge = list2;
        list2 = list2->next;
    }

    ListNode* head = merge; // keep track of the start

    // Merge remaining nodes
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            merge->next = list1;
            list1 = list1->next;
        } else {
            merge->next = list2;
            list2 = list2->next;
        }
        merge = merge->next;
    }

    // Attach the remaining list (one of them will be nullptr)
    if (list1 != nullptr) merge->next = list1;
    if (list2 != nullptr) merge->next = list2;

    return head;
}

int main() {
    // Test case 1: Normal merge
    ListNode* list1 = nullptr;
    insert(list1, 1);
    insert(list1, 2);
    insert(list1, 4);

    ListNode* list2 = nullptr;
    insert(list2, 1);
    insert(list2, 3);
    insert(list2, 4);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    ListNode* merged = mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printList(merged);

    // Test case 2: One list empty
    ListNode* list3 = nullptr;
    ListNode* list4 = nullptr;
    insert(list4, 0);

    cout << "\nList 3 (empty): ";
    printList(list3);
    cout << "List 4: ";
    printList(list4);

    ListNode* merged2 = mergeTwoLists(list3, list4);
    cout << "Merged List: ";
    printList(merged2);

    // Test case 3: Both lists empty
    ListNode* list5 = nullptr;
    ListNode* list6 = nullptr;

    cout << "\nBoth empty lists merged: ";
    ListNode* merged3 = mergeTwoLists(list5, list6);
    printList(merged3);

    return 0;
}
