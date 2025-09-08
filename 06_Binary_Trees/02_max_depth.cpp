#include <iostream>
#include <queue>
using namespace std;

// ------------------ Definition of TreeNode ------------------
// A simple structure representing a node in a binary tree
struct TreeNode {
    int val;              // Value of the node
    TreeNode* left;       // Pointer to the left child
    TreeNode* right;      // Pointer to the right child
    
    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ------------------ Class to Create Tree ------------------
class CreateTree {
public:
    /**
     * Function: buildTree
     * --------------------
     * Builds a binary tree interactively from user input using level-order traversal (BFS).
     * For each node, the user enters values for left and right children (-1 for null).
     * 
     * Time Complexity: O(N) 
     *    -> Every node is created exactly once and pushed/popped from the queue once.
     * Space Complexity: O(N) 
     *    -> Queue stores nodes level by level in the worst case.
     */
    TreeNode* buildTree() {
        int x;
        cout << "Enter the root node value (-1 for null): ";
        cin >> x;
        if (x == -1) return nullptr;

        TreeNode* root = new TreeNode(x);
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            // Left child
            cout << "Enter the left child of " << p->val << " (-1 for null): ";
            cin >> x;
            if (x != -1) {
                TreeNode* t = new TreeNode(x);
                p->left = t;
                q.push(t);
            }

            // Right child
            cout << "Enter the right child of " << p->val << " (-1 for null): ";
            cin >> x;
            if (x != -1) {
                TreeNode* t = new TreeNode(x);
                p->right = t;
                q.push(t);
            }
        }
        return root;
    }
};

/**
 * Function: maxDepth
 * -------------------
 * Finds the maximum depth (or height) of a binary tree using recursion (DFS).
 * Depth is the longest path from the root to a leaf node.
 *
 * Time Complexity: O(N)
 *    -> We visit every node exactly once.
 * Space Complexity: O(H)
 *    -> H is the height of the tree (worst case N for skewed tree, logN for balanced tree).
 */
int maxDepth(TreeNode* tree) {
    if (tree == nullptr) return 0;
    return 1 + max(maxDepth(tree->left), maxDepth(tree->right));
}

// ------------------ Driver Code ------------------
int main() {
    CreateTree ct;
    TreeNode* root = ct.buildTree();

    cout << "\nMaximum Depth of Tree: " << maxDepth(root) << endl;

    return 0;
}
