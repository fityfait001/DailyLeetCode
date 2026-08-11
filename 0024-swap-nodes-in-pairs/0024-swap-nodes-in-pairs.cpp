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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* nxt=curr->next;
        ListNode* NextHead=nxt->next;

        nxt->next=curr;
        curr->next=swapPairs(NextHead);

        return nxt;
    }
};