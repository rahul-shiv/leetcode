/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int,Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        Node *curr = new Node(node->val);
        m[node->val] = curr;
        for(auto neighbor:node->neighbors){
            auto it = m.find(neighbor->val);
            if(it==m.end()){
                cloneGraph(neighbor);
            }
            curr->neighbors.push_back(m[neighbor->val]);
        }
        return curr;
    }
};