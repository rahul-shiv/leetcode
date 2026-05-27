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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<TreeNode*>> m;
        if(root)m[0].push_back(root);
        vector<vector<int>> ans;
        for(auto x:m){
            if(x.first==ans.size())ans.push_back({});
            for(auto node:x.second){
                ans[x.first].push_back(node->val);
                if(node->left)m[x.first+1].push_back(node->left);
                if(node->right)m[x.first+1].push_back(node->right);
            }
        }
        return ans;
    }
};