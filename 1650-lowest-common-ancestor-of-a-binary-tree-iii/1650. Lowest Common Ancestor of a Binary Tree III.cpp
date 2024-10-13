/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    unordered_set<int> vis;
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *it = p;
        while(it){
            vis.insert(it->val);
            if(it==q){
                return q;
            }
            it=it->parent;
        }
        it = q;
        while(it){
            if(vis.contains(it->val)){
                return it;
            }
            it = it->parent;
        }
        return nullptr;
    }
};