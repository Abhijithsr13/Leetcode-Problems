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
void Right(TreeNode* node,int level,vector<int>&res){
    if(node==NULL) return ;
    if(level==res.size()) res.push_back(node->val);
    Right(node->right,level+1,res);
    Right(node->left,level+1,res);
}
    vector<int> rightSideView(TreeNode* root) {
         vector<int>res;
        Right(root,0,res);
        return res;
    }
};