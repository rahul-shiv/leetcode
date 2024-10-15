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
    bool isValidBST(TreeNode* root, int64_t min = INT64_MIN, int64_t max = INT64_MAX) {
        bool t = root->val>min and root->val<max;
        if(t and root->right){
            t = isValidBST(root->right,root->val,max);
        }
        if(t and root->left){
            t = isValidBST(root->left,min,root->val);
        }
        return t;
    }
};