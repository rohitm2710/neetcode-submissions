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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* curr=head;
        int carry=0;
        while(l1||l2||carry!=0){
            int n1=0,n2=0;
            if(l1) n1=l1->val;
            if(l2) n2=l2->val;
            curr->next=new ListNode(n1+n2+carry);
            carry=0;
            curr=curr->next;
            if(curr->val>9){
                carry=1;
                curr->val%=10;
            }
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return head->next;
    }
};
