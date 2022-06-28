/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return 0;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast){
                return 1;
            }
        }
        
        return 0;
    }
};

//Another approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return 0;
        }
         map<ListNode*,bool> visit;
        ListNode* temp=head;
        while(temp!=NULL){
            if(visit[temp]==true){
                return 1;
            }
            visit[temp]=true;
            temp=temp->next;
        }
        return 0;
    }
};
