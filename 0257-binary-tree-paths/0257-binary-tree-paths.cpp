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

void dfs(TreeNode* node, string path, vector<string>& allPaths) {
    if (!node) {
        return; 
    }
    if (!path.empty()) {
        path += "->";
    }
    path += to_string(node->val);

    if (!node->left && !node->right) {
        allPaths.push_back(path);
    } else {
        dfs(node->left, path, allPaths);
        dfs(node->right, path, allPaths);
    }
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPaths;
    dfs(root, "", allPaths);
    return allPaths;
    }
};