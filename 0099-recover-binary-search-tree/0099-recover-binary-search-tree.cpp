/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
       TreeNode *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

        // Helper function for inorder traversal
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            // Traverse the left subtree
            inorder(node->left);

            // Identify the nodes that are out of order
            if (prev && prev->val > node->val) {
                if (!first) {
                    first = prev;  // First out-of-order node
                    middle = node; // Middle node in case nodes are adjacent
                } else {
                    last = node;   // Last out-of-order node
                }
            }

            prev = node; // Update prev node to the current node
            inorder(node->right); // Traverse the right subtree
        };

        inorder(root); // Perform the inorder traversal to find the two nodes

        // Correct the BST by swapping the misplaced nodes
        if (first && last) {
            swap(first->val, last->val); // Non-adjacent nodes
        } else if (first && middle) {
            swap(first->val, middle->val); // Adjacent nodes
        } 
    }
};