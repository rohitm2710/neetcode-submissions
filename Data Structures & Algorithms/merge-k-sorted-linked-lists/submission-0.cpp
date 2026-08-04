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
    ListNode* merger(ListNode* list1, ListNode* list2) {
        ListNode* head= new ListNode();
        ListNode* curr=head;
        while(list1&&list2){
            if(list1->val<=list2->val){
                curr->next=list1;
                list1=list1->next;
                curr=curr->next;
            }
            else{
                curr->next=list2;
                list2=list2->next;
                curr=curr->next;
            }
        }
        while(list1){
            curr->next=list1;
            list1=list1->next;
            curr=curr->next;
        }
        while(list2){
            curr->next=list2;
            list2=list2->next;
            curr=curr->next;
        }
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        ListNode* head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=merger(head,lists[i]);
        }
        return head;
    }
};
