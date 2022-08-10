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
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
            
        }
        sort(v.begin(),v.end());
       ListNode* temp1=head;
        int i=0;
        while(temp1!=NULL){
            temp1->val=v[i];
            temp1=temp1->next;
            i++;
        }
        temp1=head;
        return temp1;
        
    }
};