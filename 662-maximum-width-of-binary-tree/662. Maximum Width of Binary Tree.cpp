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
    int widthOfBinaryTree(TreeNode* root) {
        uint64_t ans = 1;
        vector<uint64_t> m(3000,-1);
        queue<tuple<TreeNode*,uint64_t,uint64_t>> q;
        uint64_t d,p;
        TreeNode*curr;
        q.push({root,0,0});
        while(!q.empty()){
            tie(curr,d,p) = q.front();
            q.pop();
            if(m[d]==-1){
                m[d]=p;
            }else{
                ans = max(ans,p-m[d]+1);
            }
            if(curr->left){
                q.push({curr->left,d+1,p*2});
            }
            if(curr->right){
                q.push({curr->right,d+1,p*2+1});
            }
        }
        return ans;
    }
};