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
    void inorder(TreeNode*root, int &ans, int &k){
        if(!root or ans>=0)return ;
        inorder(root->left, ans,k);
        k--;
        if(!k){
            ans=root->val;return;
        }
        inorder(root->right,ans,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        inorder(root, ans, k);
        return ans;
    }
};