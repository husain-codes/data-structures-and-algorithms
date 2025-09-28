#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    // Helper with carry
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) return nullptr;

        int sum = carry;
        if (l1) sum += l1->val;
        if (l2) sum += l2->val;

        ListNode* node = new ListNode(sum % 10);
        node->next = add(l1 ? l1->next : nullptr,
                         l2 ? l2->next : nullptr,
                         sum / 10);
        return node;
    }

public:
    // LeetCode-required function
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};

int main() {
    // Number 1: 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9  (i.e. 9,999,999)
    ListNode* l1 = new ListNode(9,
                    new ListNode(9,
                    new ListNode(9,
                    new ListNode(9,
                    new ListNode(9,
                    new ListNode(9,
                    new ListNode(9)))))));

    // Number 2: 9 -> 9 -> 9 -> 9  (i.e. 9,999)
    ListNode* l2 = new ListNode(9,
                    new ListNode(9,
                    new ListNode(9,
                    new ListNode(9))));

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Print result list
    cout << "Result: ";
    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
