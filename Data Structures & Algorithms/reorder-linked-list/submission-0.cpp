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
    void reorderList(ListNode* head) {
        if(!head->next||!head->next->next)  return;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second=slow->next;
        ListNode* prev=nullptr;
        slow->next=nullptr;
        ListNode* temp;
        while(second){
            temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }
        ListNode* curr=head;
        second=prev;
        while(second){
            temp=second->next;
            second->next=curr->next;
            curr->next=second;
            curr=curr->next->next;
            second=temp;
        }
    }
};
