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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>> m;
        vector<vector<int>> ans;
        queue<tuple<TreeNode*,int,int>> q;
        TreeNode* curr;
        int x,y;
        q.push({root,0,0});
        while(!q.empty()){
            tie(curr,x,y) = q.front();
            q.pop();
            m[x].insert({y,curr->val});
            if(curr->left){
                q.push({curr->left,x-1,y+1});
            }
            if(curr->right){
                q.push({curr->right,x+1,y+1});
            }
        }
        for(auto &u:m){
            ans.push_back({});
            for(auto &v:u.second){
                ans.back().push_back(v.second);
            }
        }
        return ans;
    }
};