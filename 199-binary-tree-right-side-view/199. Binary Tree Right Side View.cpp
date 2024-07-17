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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return{};
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        TreeNode* curr;
        int d;
        q.push({root,0});
        while(!q.empty()){
            tie(curr,d)=q.front();
            q.pop();
            if(d==ans.size())ans.push_back(0);
            ans[d]=curr->val;
            if(curr->left)q.push({curr->left,d+1});
            if(curr->right)q.push({curr->right,d+1});
        }
        return ans;
    }
};