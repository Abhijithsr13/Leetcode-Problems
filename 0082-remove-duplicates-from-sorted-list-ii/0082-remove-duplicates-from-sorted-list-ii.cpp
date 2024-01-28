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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* dummy=new ListNode(-1);
         dummy->next=head;
        ListNode* temp=head;
        ListNode* prev=dummy;
        while(temp!=NULL&&temp->next!=NULL){
            if(temp->val==temp->next->val){
                while(temp->next && temp->val == temp->next->val) {
                temp = temp->next;
            }
            
                prev->next=temp->next;
                }
                else{
                    prev=temp;}
                    temp=temp->next;
                
        }
        return dummy->next;
    }
};