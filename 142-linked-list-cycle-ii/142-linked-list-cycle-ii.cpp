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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,bool> visit;
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        while(temp!=NULL){
            if(visit[temp]==true){
                break;
            }
            visit[temp]=true;
            temp=temp->next;
        }
        return temp;
    }
};