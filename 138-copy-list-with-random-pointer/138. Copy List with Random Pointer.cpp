/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        auto it = m.find(head);
        if(it!=m.end())return it->second;
        m[head]= new Node(head->val);
        m[head]->next = copyRandomList(head->next);
        m[head]->random = copyRandomList(head->random);
        return m[head];
    }
};