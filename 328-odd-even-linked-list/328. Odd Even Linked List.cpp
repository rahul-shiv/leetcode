/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* oh = head, *eh = head->next, *oc,*ec;
        oc = oh;
        ec = eh;
        while(true){
            if(ec and ec->next){
                oc->next = ec->next;
                oc = oc->next;
            }else{
                break;
            }
            if(oc and oc->next){
                ec->next = oc->next;
                ec = ec->next;
            }else{
                break;
            }

        }
        oc->next = eh;
        if(ec)ec->next = nullptr;
        return oh;
    }
};