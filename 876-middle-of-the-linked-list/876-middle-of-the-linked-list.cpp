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
    int getlength(ListNode *head){
    int len =0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}
public:
    ListNode* middleNode(ListNode* head) {
    int len =getlength(head);
    int ans=len/2;    //len/2+1 nahi krege 
    int cnt=0;
    ListNode*temp=head;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
    
    }
};