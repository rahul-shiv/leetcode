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
    vector<vector<int>> ans;
public:
    void solve(TreeNode* root, int targetSum, vector<int> &arr){
        targetSum-=root->val;
        arr.push_back(root->val);
        if(!targetSum and !root->left and !root->right) ans.push_back(arr);
        if(root->left)solve(root->left, targetSum, arr);
        if(root->right)solve(root->right, targetSum, arr);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return ans;
        vector<int> arr;
        solve(root, targetSum,arr);
        return ans;
    }
};