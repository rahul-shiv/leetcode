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
    unordered_map<double,double> m;
    int ans;
public:
    void solve(TreeNode* root, int targetSum, double s = 0){
        s+=root->val;
        auto t = m.find(s-targetSum);
        if(t!=m.end())ans+=t->second;
        m[s]+=1;
        if(root->left)solve(root->left,targetSum,s);
        if(root->right)solve(root->right,targetSum,s);
        m[s]-=1;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        m[0]=1;
        ans = 0;
        solve(root,targetSum);
        return ans; 
    }
};