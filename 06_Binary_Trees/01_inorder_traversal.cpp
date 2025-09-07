#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative inorder traversal (Left → Root → Right)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        // 1. Traverse left subtree
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        // 2. Visit node
        curr = st.top();
        st.pop();
        inorder.push_back(curr->val);
        // 3. Traverse right subtree
        curr = curr->right;
    }
    return inorder;
}

// Utility: Print vector
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    /*
        Build the following tree:
        
                1
                 \
                  2
                 /
                3
    */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Test Case 1: Inorder traversal of tree [1, null, 2, 3] -> ";
    vector<int> res1 = inorderTraversal(root);
    printVector(res1);  // Expected: 1 3 2

    /*
        Another tree:
        
                4
               / \
              2   5
             / \
            1   3
    */
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);

    cout << "Test Case 2: Inorder traversal of tree [4,2,5,1,3] -> ";
    vector<int> res2 = inorderTraversal(root2);
    printVector(res2);  // Expected: 1 2 3 4 5

    return 0;
}
