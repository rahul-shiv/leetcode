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
    int ans = 0;
public:
    int sumNumbers(TreeNode* root, int t=0) {
        if(root->left){
            sumNumbers(root->left,t*10+root->val);
        }
        if(root->right){
            sumNumbers(root->right,t*10+root->val);
        }
        if(!root->left and !root->right){
            ans += t*10+root->val;
        }
        return ans;
    }
};