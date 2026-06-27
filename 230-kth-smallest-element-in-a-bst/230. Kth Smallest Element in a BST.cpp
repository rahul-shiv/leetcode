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
    int ans = 0;
    int curr = 0;
    void inorder(TreeNode* root, int k){
        if(curr==k) return;
        if(root->left){
            inorder(root->left, k);
        }
        curr+=1;
        if(curr == k){ans = root->val;return;}
        
        if(root->right){
            inorder(root->right, k);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};