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
public:
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
};

// ------------------ Helper to find a node ------------------
TreeNode* findNode(TreeNode* root, int value) {
    if (root == nullptr) return nullptr;
    if (root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    if (left != nullptr) return left;
    return findNode(root->right, value);
}

// ------------------ Lowest Common Ancestor ------------------
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) return root;
    return left != nullptr ? left : right;
}

// ------------------ Driver Code ------------------
int main() {
    CreateTree treeBuilder;
    TreeNode* root = treeBuilder.buildTree();

    int pVal, qVal;
    cout << "\nEnter value of node p: ";
    cin >> pVal;
    cout << "Enter value of node q: ";
    cin >> qVal;

    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    if (p && q) {
        TreeNode* lca = lowestCommonAncestor(root, p, q);
        cout << "\nLowest Common Ancestor of " << p->val << " and " << q->val 
             << " is: " << lca->val << endl;
    } else {
        cout << "\nOne or both nodes not found in the tree.\n";
    }

    return 0;
}