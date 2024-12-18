/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head==nullptr){
            head = new Node(insertVal);
            head->next=head;
            return head;
        }
        Node *temp=head;
        while(temp->next!=head){
            if(temp->val<=temp->next->val){
                if(insertVal>temp->val and insertVal <=temp->next->val)break;
            }else{
                if(insertVal>=temp->val or insertVal <=temp->next->val)break;
            }
            temp=temp->next;
        }
        Node *t2 = temp->next;
        temp->next = new Node(insertVal);
        temp->next->next=t2;
        return head;
    }
};