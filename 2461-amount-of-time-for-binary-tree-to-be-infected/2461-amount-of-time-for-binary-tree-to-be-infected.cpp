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
   TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp, int start) {
        // Queue for BFS
        queue<TreeNode*> q;
        // Push the root node to the queue
        q.push(root);
        TreeNode* res = new TreeNode(-1);

        while (!q.empty()) {
            // Get the front node from the queue
            TreeNode* node = q.front();
            q.pop();
            // Check if this is the start node
            if (node->val  == start) res = node;
            // Map the left child to its parent
            if (node->left != nullptr) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            // Map the right child to its parent
            if (node->right != nullptr) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
     int findMaxDistance(unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* target) {
        // Queue for BFS to find max distance
        queue<TreeNode*> q;
        q.push(target);
        // Map to check visited nodes
        unordered_map<TreeNode*, int> vis;
        vis[target] = 1;
        int maxi = 0;

        while (!q.empty()) {
            int size = q.size();
            int fl = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check left child
                if (node->left != nullptr && vis.find(node->left) == vis.end()) {
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }

                // Check right child
                if (node->right != nullptr && vis.find(node->right) == vis.end()) {
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                // Check parent node
                if (mpp.find(node) != mpp.end() && vis.find(mpp[node]) == vis.end()) {
                    fl = 1;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            // Increment max distance if any node was burned
            if (fl == 1) maxi++;
        }
        return maxi;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        // Get the target node (starting node for burning)
        TreeNode* target = bfsToMapParents(root, mpp, start);
        // Find the maximum distance to burn the tree
        int maxi = findMaxDistance(mpp, target);
        return maxi;
    }
};