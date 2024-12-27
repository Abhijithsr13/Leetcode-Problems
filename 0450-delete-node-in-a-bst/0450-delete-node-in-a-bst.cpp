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
TreeNode* connector(TreeNode* root) {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        TreeNode* leftchild = root->left;
        TreeNode* leftmost_child_in_right_subtree = root->right;
        while (leftmost_child_in_right_subtree->left) {
            leftmost_child_in_right_subtree =
                leftmost_child_in_right_subtree->left;
        }
        leftmost_child_in_right_subtree->left = leftchild;

        return root->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
         if (root == NULL)
            return NULL;
        if (root->val== key) {
            return connector(root);
        }
        TreeNode* node = root;
        while (node) {
            if (node->val > key) {
                if (node->left && node->left->val== key) {
                    node->left = connector(node->left);
                    break;
                } else {
                    node = node->left; 
                }
            }

            else {
                if (node->right && node->right->val == key) {
                    node->right = connector(node->right);
                    break;
                } else {
                    node = node->right; 
                }
            }
        }
        return root;
    }
};