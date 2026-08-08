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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack <int> st;
        ListNode* temp=head;
        ListNode* leftSide;
        ListNode* rightSide;
        int count=1;
        while(temp!=NULL){
            if(count==left){
               leftSide=temp; 
            }
            if(count==right){
                rightSide=temp->next;
            }
            count++;
            temp=temp->next;
        }
        temp=leftSide;
        while(leftSide!=rightSide ){
            st.push(leftSide->val);
            leftSide=leftSide->next;
        }
        while(temp!=rightSide){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};