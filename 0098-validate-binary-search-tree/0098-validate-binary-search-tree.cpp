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
    bool isValidBST(TreeNode* root) {
         return isvalid(root,LONG_MIN, LONG_MAX);
    }
    private:
		bool isvalid(TreeNode* node,long long min, long long max){
			if(node==nullptr) return true;
			if (node->val <= min || node->val >= max) return false;
			   bool Lisvalid = isvalid(node->left, min, node->val);
			      bool RisValid = isvalid(node->right,node->val , max);
		return Lisvalid&&RisValid;
		}
};