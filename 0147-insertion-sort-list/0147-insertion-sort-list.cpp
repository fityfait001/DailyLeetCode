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
// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         ListNode* pre=head;
//         ListNode* cur=head->next;
//         while(cur!=NULL){
//             if(cur->val>=pre->val){
//                 pre=cur;
//                 cur=cur->next;
//             }
//             ListNode* temp=cur;
//             pre->next=cur->next;
//             cur=cur->next;
//         }
//         ListNode* Trev=head;
//         ListNode* bck=head;
//         while(temp->val>Trev->val){
//             bck=Trev;
//             Trev=Trev->next;
//         }
//     }
// };

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* pre = head;
        ListNode* cur = head->next;

        while(cur){
            if(cur->val >= pre->val){
                pre = cur;
                cur = cur->next;
                continue;
            }

            // Remove current node
            pre->next = cur->next;

            // Find insertion position
            ListNode* prev = NULL;
            ListNode* temp = head;

            while(temp->val < cur->val){
                prev = temp;
                temp = temp->next;
            }

            // Insert at beginning
            if(prev == NULL){
                cur->next = head;
                head = cur;
            }
            else{
                prev->next = cur;
                cur->next = temp;
            }

            cur = pre->next;
        }

        return head;
    }
};