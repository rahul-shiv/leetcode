/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    pair<Node*,Node *> solve(Node *root){
        if(!root)return {root,root};
        pair<Node*,Node *>ret = make_pair(root,root);
        if(root->left){
            pair<Node*,Node *>l = solve(root->left);
            l.second->right = root;
            root->left = l.second;
            ret.first=l.first;
        }
        if(root->right){
            pair<Node*,Node *>r = solve(root->right);
            r.first->left=root;
            root->right=r.first;
            ret.second=r.second;
        }
        return ret;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)return root;
        Node* head = root;
        if(root->left){
            pair<Node*,Node *>l = solve(root->left);
            l.second->right = root;
            root->left = l.second;
            head = l.first;
        }
        if(root->right){
            pair<Node*,Node *>r = solve(root->right);
            r.first->left=root;
            root->right=r.first;
            r.second->right=head;
            head->left=r.second;
        }else{
            root->right=head;
            head->left=root;
        }
        return head;
    }
};