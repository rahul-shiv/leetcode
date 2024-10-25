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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root1,root2});
        TreeNode* c1, *c2;
        while(!q.empty()){
            tie(c1,c2)=q.front();
            q.pop();
            if(!c1 and !c2)continue;
            if(!c1 or !c2 or c1->val!=c2->val){
                return false;
            }
            if(c1->left){
                if(c2->left and c2->left->val==c1->left->val){
                    q.push({c1->left,c2->left});
                    q.push({c1->right,c2->right});
                }else{
                    q.push({c1->left,c2->right});
                    q.push({c1->right,c2->left});
                }
            }else if(c1->right){
                if(c2->left and c2->left->val==c1->right->val){
                    q.push({c1->right,c2->left});
                    q.push({c1->left,c2->right});
                }else{
                    q.push({c1->right,c2->right});
                    q.push({c1->left,c2->left});
                }

            }else if(c2->left or c2->right){
                return false;
            }
        }
        return true;
    }
};