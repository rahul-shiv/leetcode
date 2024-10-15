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
        vector<vector<TreeNode*>> tr;
        ans.push_back({root->val});
        tr.push_back({root});
        int i = 0;
        auto it = tr.begin();
        while(i<tr.size()){
            for(auto node:tr[i]){
                if(node->left||node->right){
                    if(tr.size()-1==i){
                        tr.push_back({});
                        ans.push_back({});
                    }
                    if(node->left){
                        tr.back().push_back(node->left);
                        ans.back().push_back({node->left->val});
                    }
                    if(node->right){
                        tr.back().push_back(node->right);
                        ans.back().push_back({node->right->val});
                    }
                }
            }
            i++;
        }
        return ans;
    }
};