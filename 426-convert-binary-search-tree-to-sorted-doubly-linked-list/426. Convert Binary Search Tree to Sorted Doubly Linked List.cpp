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
    Node * solve(Node *root){
        if(!root)return root;
        Node*l = solve(root->left);
        if(l){
            l->right = root;
            root->left = l;
        }
        Node*r = solve(root->right);
        Node *temp = r;
        if(temp){
            while(temp->left){
                temp=temp->left;
            }
            temp->left=root;
            root->right=temp;
        }else{
            r = root;
        }
        return r;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)return root;
        Node* l = solve(root->left);
        Node *head;
        if(l){
            root->left = l;
            l->right=root;
            while(l->left){
                l=l->left;
            }
        }else{
            l = root;
        }
        head = l;
        Node* r = solve(root->right);
        if(r){
            r->right=head;
            head->left=r;
            while(r->left){
                r=r->left;
            }
            root->right=r;
            r->left=root;
        }else{
            root->right=head;
            head->left=root;
        }
        return head;
    }
};