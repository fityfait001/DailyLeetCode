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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==n){
            return head->next;
        }
        int nxt=count-n;
        temp=head;
        int key=0;
        while(temp!=NULL){
            key++;
            if(key==nxt){
                if(temp->next)
                temp->next=temp->next->next;
            }
            temp=temp->next;  
        }
        return head;
    }
};