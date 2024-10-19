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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ah= new ListNode(), *ait;
        ait =ah;
        auto comp = [](const ListNode* a,const ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)> pq;
        for(auto l:lists){
            if(l)pq.push(l);
        }
        ListNode* curr;
        while(!pq.empty()){
            curr = pq.top();
            pq.pop();
            ait->next = new ListNode(curr->val);
            ait = ait->next;
            if(curr->next){
                pq.push(curr->next);
            }
        }
        return ah->next;
    }
};