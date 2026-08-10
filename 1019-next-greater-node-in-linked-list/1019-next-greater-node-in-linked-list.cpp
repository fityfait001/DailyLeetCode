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
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int>ans;
//         if(head==NULL) return ans;
//         ListNode* temp=head;
//         ListNode* nxt=head->next;
//         int count=0;
//         while(temp!=nullptr){
//             while(nxt!=nullptr){
//                 if(temp->val<nxt->val){
//                     ans.push_back(nxt->val);
//                     count=1;
//                     break;
//                 }
//                 nxt=nxt->next;
//             }
//             if(count==0){
//                 ans.push_back(0);
                
//             }
//             count=0;
//             temp=temp->next;
//             nxt=nxt->next;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            ListNode* nxt = temp->next; 
            int count = 0;
            
            while (nxt != nullptr) {
                if (temp->val < nxt->val) {
                    ans.push_back(nxt->val);
                    count = 1;
                    break;
                }
                nxt = nxt->next; 
            }
            
            if (count == 0) {
                ans.push_back(0); 
            }
            
            temp = temp->next;
        }
        
        return ans;
    }
};