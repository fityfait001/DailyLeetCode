/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
        
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        vector<ListNode*>ans;
        while(temp!=NULL){
            
            if(find(ans.begin(), ans.end(), temp)!=ans.end()){
                return true;
            }
            ans.push_back(temp);
            temp=temp->next;
        
        }
        return false;
        
    }
};