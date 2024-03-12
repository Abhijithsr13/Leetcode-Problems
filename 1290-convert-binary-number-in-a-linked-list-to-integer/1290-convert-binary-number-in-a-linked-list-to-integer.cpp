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
 int Square(int k){
  
   return pow(2,k);


 }
    int getDecimalValue(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* temp=head;
        long sum=0;
        int cnt=0;
        while(temp!=NULL&&temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->val==1){
                sum+= Square(cnt);
            }
            else {
                sum+=0;
            }
            temp=temp->next;
            cnt--;
        }return sum;
    }
};