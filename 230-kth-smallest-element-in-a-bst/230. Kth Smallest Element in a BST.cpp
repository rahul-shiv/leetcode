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
    int dfs(TreeNode*root){
        int x = 1;
        if(root->left)x+=dfs(root->left);
        if(root->right)x+=dfs(root->right);
        return x;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int l = 0;
        if(root->left) l = dfs(root->left);
        if(l>=k) return kthSmallest(root->left,k);
        k-=l;
        if(k==1)return root->val;
        return kthSmallest(root->right, k-1);
    }
};