/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, int val, int depth, int currdepth) {
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            new_root->right = nullptr;
            return new_root;
        }

        if (!root) {
            return nullptr;
        }

        if (currdepth == depth - 1) {
            TreeNode* leftman = root->left;
            TreeNode* rightman = root->right;

            root->left = new TreeNode(val);
            root->left->left = leftman;
            root->left->right = nullptr;

            root->right = new TreeNode(val);
            root->right->left = nullptr;
            root->right->right = rightman;

            return root;
        }

        root->left = helper(root->left, val, depth, currdepth + 1);
        root->right = helper(root->right, val, depth, currdepth + 1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return helper(root, val, depth, 1);
    }
};