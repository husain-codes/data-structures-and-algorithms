#include <iostream>
#include <queue>
using namespace std;

// ------------------ Definition of TreeNode ------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ------------------ Class to Create Tree ------------------
class CreateTree {
    int i = 0;       // Counter for inorder traversal
    int ksmall;      // Stores the kth smallest value
public:
    // Build tree using level-order input
    TreeNode* buildTree() {
        int val;
        cout << "Enter the root node value (-1 for null): ";
        cin >> val;
        if (val == -1) return nullptr;

        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            // Left child
            cout << "Enter the left child of " << current->val << " (-1 for null): ";
            cin >> val;
            if (val != -1) {
                TreeNode* leftNode = new TreeNode(val);
                current->left = leftNode;
                q.push(leftNode);
            }

            // Right child
            cout << "Enter the right child of " << current->val << " (-1 for null): ";
            cin >> val;
            if (val != -1) {
                TreeNode* rightNode = new TreeNode(val);
                current->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }

    int kthSmallest(TreeNode* root, int k);
    bool inorderTraversal(TreeNode* root, int k);
};

// ------------------ Function Definitions ------------------
int CreateTree::kthSmallest(TreeNode* root, int k) {
    i = 0; // reset counter
    inorderTraversal(root, k);
    return ksmall;
}

bool CreateTree::inorderTraversal(TreeNode* root, int k) {
    if (root == nullptr) return false;

    if (inorderTraversal(root->left, k)) return true;

    if (++i == k) {
        ksmall = root->val;
        return true;
    }

    if (inorderTraversal(root->right, k)) return true;

    return false;
}

// ------------------ Driver Code ------------------
int main() {
    CreateTree ct;
    TreeNode* root = ct.buildTree();

    int k;
    cout << "\nEnter the value of k to find kth smallest element in BST: ";
    cin >> k;

    int result = ct.kthSmallest(root, k);
    cout << "The " << k << "th smallest element in the BST is: " << result << endl;

    return 0;
}
