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
    unordered_map<TreeNode*, TreeNode*> parent;
public:
    TreeNode* findk(TreeNode* root, int k){
        if(root->val==k)return root;
        TreeNode *l = nullptr, *r = nullptr;
        if(root->left){
            parent[root->left]=root;
            l = findk(root->left,k);
        }
        if(root->right){
            parent[root->right]=root;
            r = findk(root->right,k);
        }
        if(l)return l;
        return r;
    }
    int findClosestLeaf(TreeNode* root, int k) {
        TreeNode* x = findk(root,k);
        queue<tuple<TreeNode*, TreeNode*,int>> q;
        TreeNode* curr, *prev;
        int d;
        q.push({x,nullptr,0});
        pair<int,int> ans = {1,1001};
        while(!q.empty()){
            tie(curr,prev,d)=q.front();
            q.pop();
            if(curr->left==nullptr and curr->right==nullptr){
                if(ans.second>d){
                    ans.first = curr->val;
                    ans.second = d;
                }
            }
            if(curr->left and curr->left!=prev){
                q.push({curr->left,curr,d+1});
            }
            if(curr->right and curr->right!=prev){
                q.push({curr->right,curr,d+1});
            }
            auto it = parent.find(curr);
            if(it!=parent.end() and it->second!=prev){
                q.push({it->second,curr,d+1});
            }
            
        }
        return ans.first;
    }
};