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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)return {};
        unordered_map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        TreeNode* head;
        int pos;
        q.push({root,0});
        int l=0,r=0;
        while(!q.empty()){
            tie(head,pos)=q.front();
            q.pop();
            m[pos].push_back(head->val);
            l=min(l,pos);
            r=max(r,pos);
            if(head->left)q.push({head->left,pos-1});
            if(head->right)q.push({head->right,pos+1});
        }
        for(int i=l;i<=r;i++) ans.push_back(move(m[i]));
        return ans;
    }
};