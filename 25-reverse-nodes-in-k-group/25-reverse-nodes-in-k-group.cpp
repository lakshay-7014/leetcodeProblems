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
         int leng(ListNode* head){
       ListNode* temp =head;
       int count=0;
       while(temp != NULL){
       temp = temp->next;
       count++;
       }
      return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
      int len=leng(head);
       if(len<k){
           return head;
       }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forw=curr->next;
        int cnt=0;
        while( cnt<k){
            forw=curr->next;
             curr->next=prev;
            prev=curr;
            curr=forw;
            cnt++;
        }
        if(forw!=NULL){
            head->next= reverseKGroup(forw,k);
        }
        return prev;
        
    }
};