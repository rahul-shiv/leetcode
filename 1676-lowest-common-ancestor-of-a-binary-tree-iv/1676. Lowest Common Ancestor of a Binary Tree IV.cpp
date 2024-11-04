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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(!root) return root;
        for(auto &x:nodes){
            if(root==x)return root;
        }
        TreeNode * l = lowestCommonAncestor(root->left,nodes);
        TreeNode * r = lowestCommonAncestor(root->right,nodes);
        if(l and r){
            return root;
        }else if(l){
            return l;
        }else if(r){
            return r;
        }else{
            return nullptr;
        }
    }
};