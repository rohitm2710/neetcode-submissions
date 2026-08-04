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
private:
    int length=0;
    int k;
    ListNode* needed=nullptr;
    void core(ListNode* head){
        if(!head) return;
        length++;
        int curr=length;
        core(head->next);
        if(length-k==curr){
            needed=head;
        }
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        length=0;
        k=n;
        core(head);
        if(!needed){
            return head->next;
        }
        needed->next=needed->next->next;
        return head;
    }
};
