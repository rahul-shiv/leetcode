/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)return root;
        TreeNode *l = nullptr, *r = nullptr;
        if(root->left) l = lowestCommonAncestor(root->left,p,q);
        if(root->right) r = lowestCommonAncestor(root->right,p,q);
        if(l and r)return root;
        if(l) return l;
        if(r) return r;
        return nullptr;
    }
};