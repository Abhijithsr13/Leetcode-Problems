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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodesMap;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});  
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodesMap[x][y].push(node->val);

            if (node->left != nullptr) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right != nullptr) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        for (auto& p : nodesMap) {
            vector<int> column;
            for (auto& q : p.second) {
                while (!q.second.empty()) {
                    column.push_back(q.second.top());
                    q.second.pop();
                }
            }
            result.push_back(column);
        }

        return result;
    }
};