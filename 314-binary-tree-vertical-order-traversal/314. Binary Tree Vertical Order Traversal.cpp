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
        vector<vector<int>> l,r;
        queue<pair<TreeNode*,int>> q;
        TreeNode* head;
        int pos;
        q.push({root,0});
        while(!q.empty()){
            tie(head,pos)=q.front();
            q.pop();
            if(pos>=0){
                if(pos==r.size())r.push_back({});
                r[pos].push_back(head->val);
            }else{
                int pos2=abs(pos)-1;
                if(pos2==l.size())l.push_back({});
                l[pos2].push_back(head->val);
            }
            if(head->left)q.push({head->left,pos-1});
            if(head->right)q.push({head->right,pos+1});
        }
        vector<vector<int>> ans(l.rbegin(),l.rend());
        ans.insert(ans.end(),r.begin(),r.end());
        return ans;
    }
};