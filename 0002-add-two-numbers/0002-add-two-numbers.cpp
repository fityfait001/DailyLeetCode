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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//         if(l1 == NULL && l2 == NULL){
//             return NULL;
//         }

//         if(l1 == NULL){
//             return l2;
//         }

//         if(l2 == NULL){
//             return l1;
//         }

//         ListNode* sum = new ListNode(0, nullptr);
//         ListNode* temp = sum;
//         int carr = 0;

//         // YOUR CODE:
//         /*
//         while(l1 != NULL && l2 != NULL){
//             if((l1->val+l2->val)>=10){
//                 sum->val = carr+l1->val+l2->val-10;
//                 carr = (l1->val+l2->val)/10;
//             }
//             else
//                 sum->val = carr+l1->val+l2->val;

//             sum->next = new ListNode(0);
//             sum = sum->next;

//             l1 = l1->next;
//             l2 = l2->next;
//         }

//         if(l1 != NULL || l2 != NULL){
//             while(l1 != NULL){
//                 sum->val = l1->val;
//                 l1 = l1->next;
//             }

//             while(l2 != NULL){
//                 sum->val = l2->val;
//                 l2 = l2->next;
//             }
//         }
//         */

//         while(l1 != NULL || l2 != NULL || carr != 0){

//     int a = (l1 != NULL) ? l1->val : 0;
//     int b = (l2 != NULL) ? l2->val : 0;

//     int total = a + b + carr;

//     sum->val = total % 10;
//     carr = total / 10;

//     if(l1 != NULL)
//         l1 = l1->next;

//     if(l2 != NULL)
//         l2 = l2->next;

//     if(l1 != NULL || l2 != NULL || carr != 0){
//         sum->next = new ListNode(0);
//         sum = sum->next;
//     }
// }

// return temp;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0;
        int sum=0;
        while(l1!=NULL || l2!=  NULL){
            sum=carry;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            curr->next=newNode;
            curr=curr->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry){
            ListNode * newNode=new ListNode(carry);
            curr->next=newNode;
        }
        return dummy->next;
    }
};