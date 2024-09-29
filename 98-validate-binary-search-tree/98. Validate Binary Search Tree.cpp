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
    bool isValidBST(TreeNode* root, int64_t small = INT64_MIN, int64_t big = INT64_MAX) {
        if(root->val<=small or root->val>=big)return false;
        bool t = true;
        if(root->left){
            t &= isValidBST(root->left,small,root->val);
        }
        if(t && root->right){
            t &= isValidBST(root->right,root->val,big);
        }
        return t;   
    }
};