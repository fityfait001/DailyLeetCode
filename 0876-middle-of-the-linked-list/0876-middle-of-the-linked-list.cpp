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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        if(head==NULL) return NULL;
        int count=1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        int middle=count/2;
        int key=0;
        while(key<middle){
            temp=temp->next;
            key++;
        }
        if(count%2==0){
            return temp;
        }
        return temp;

    }
};