/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL || root->left==NULL){
            return root;
        }
        Node* cur=root;
        while(cur->left){
            Node* temp=cur->left;
            while(cur){
                cur->left->next=cur->right;
                if(cur->next)
                cur->right->next=cur->next->left;

                cur=cur->next;
            }
            cur=temp;
        }
        return root;


        // queue<Node*>q;
        // q.push(root);
        // q.push(NULL);
        // Node* prev= NULL;
        // while(!q.empty()){
        //     Node* curr=q.front();
        //     q.pop();
        //     if(curr==NULL){
        //         if(q.size()==0)
        //         break;
        //         q.push(NULL);
        //     }
        //     else{
        //         if(curr->left!=NULL){
        //             q.push(curr->left);
        //         }
        //         if(curr->right!=NULL){
        //             q.push(curr->right);
        //         }
        //         if(prev!=NULL){
        //             prev->next=curr;
        //         }
        //     }
        //     prev=curr;
        // }
        // return root;
            
        
        
    }
};