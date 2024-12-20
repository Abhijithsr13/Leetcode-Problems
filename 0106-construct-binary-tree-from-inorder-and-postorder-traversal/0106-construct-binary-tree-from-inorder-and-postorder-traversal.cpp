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
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart,
                              int postEnd,
                              unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);
        int rootIndexInorder = inorderMap[rootValue];
        int leftSubtreeSize = rootIndexInorder - inStart;
        root->left = buildTreeHelper(
            inorder, inStart, rootIndexInorder - 1, postorder, postStart,
            postStart + leftSubtreeSize - 1, inorderMap);
        root->right = buildTreeHelper(inorder, rootIndexInorder + 1, inEnd,
                                      postorder, postStart + leftSubtreeSize,
                                      postEnd - 1, inorderMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.empty() || postorder.empty() ||
            inorder.size() != postorder.size()) {
            return nullptr;
        }
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0,
                               postorder.size() - 1, inorderMap);
    }
};