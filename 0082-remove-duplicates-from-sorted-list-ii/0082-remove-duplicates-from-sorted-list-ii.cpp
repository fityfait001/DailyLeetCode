// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>freq;
        if(head==NULL) return NULL;

        ListNode* temp = head;
        ListNode* last=NULL;

        while(temp != NULL) {
            freq[temp->val]++;
            temp = temp->next;
        }
        temp=head;
        for(auto x:freq) {
            if(x.second==1){
                temp->val=x.first;
                last=temp;
                temp=temp->next;
            }
        }
        
        if(last != NULL)
            last->next = NULL;
        else
            head = NULL;
        return head;

    }
};

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
//     ListNode* deleteDuplicates(ListNode* head) {
//         if(head == NULL) return NULL;

//         ListNode* temp = head;
//         set<int> os;

//         while(temp != NULL) {
//             os.insert(temp->val);
//             temp = temp->next;
//         }

//         temp = head;
//         ListNode* prev = NULL;

//         for(int x : os) {
//             temp->val = x;
//             prev = temp;
//             temp = temp->next;
//         }

//         prev->next = NULL;

//         return head;
//     }
// };