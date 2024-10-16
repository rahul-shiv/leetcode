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
    int ans;
    int solve(TreeNode* root){
        if(!root)return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        ans = max(ans,root->val);
        ans = max(ans,l+root->val);
        ans = max(ans,r+root->val);
        ans = max(ans,l+r+root->val);
        return max(max(l,r),0)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};