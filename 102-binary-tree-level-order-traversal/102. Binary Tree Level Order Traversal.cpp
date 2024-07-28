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
        if(!root)return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode* ,int>> q;
        q.push({root,0});
        TreeNode * node;
        int d;
        while(!q.empty()){
            tie(node,d) = q.front();
            q.pop();
            if(d==ans.size()){
                ans.push_back({});
            }
            ans[d].push_back(node->val);
            if(node->left)q.push({node->left,d+1});
            if(node->right)q.push({node->right,d+1});
        }
        return ans;
    }
};