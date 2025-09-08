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

// ------------------ Diameter of Binary Tree ------------------
int maxDiameter = 0;

/**
 * Function: calculateDepth
 * -------------------------
 * Recursively computes the depth (height) of the tree using DFS.
 * While calculating depth, it also updates the maximum diameter.
 * 
 * Diameter at a node = depth(leftSubtree) + depth(rightSubtree).
 *
 * Time Complexity: O(N)
 *    -> Each node is visited exactly once.
 * Space Complexity: O(H)
 *    -> H is the height of the tree (O(N) in skewed, O(logN) in balanced).
 */
int calculateDepth(TreeNode* node) {
    if (node == nullptr) return 0;

    int leftDepth = calculateDepth(node->left);
    int rightDepth = calculateDepth(node->right);

    // Update global maximum diameter if current diameter is larger
    maxDiameter = max(maxDiameter, leftDepth + rightDepth);

    // Return height of current subtree
    return 1 + max(leftDepth, rightDepth);
}

/**
 * Function: getDiameter
 * ----------------------
 * Wrapper function to calculate diameter of a binary tree.
 * 
 * Returns the length of the longest path between any two nodes.
 */
int getDiameter(TreeNode* root) {
    maxDiameter = 0;   // reset before calculation
    calculateDepth(root);
    return maxDiameter;
}

// ------------------ Driver Code ------------------
int main() {
    CreateTree treeBuilder;
    TreeNode* root = treeBuilder.buildTree();

    cout << "\nDiameter of the Binary Tree: " << getDiameter(root) << endl;

    return 0;
}
