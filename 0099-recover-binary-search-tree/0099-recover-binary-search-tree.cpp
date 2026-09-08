/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     void inorder(TreeNode* &root,vector<int>&v){
//         if(root==NULL) return ;
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
//     void recoverTree(TreeNode* root) {
//         vector<int>v;
//         inorder(root,v);
//         sort(v.begin(),v.end());
//         vector<int>c;
//         inorder(root,c);
//         for(int i=0;i<c.size();i++){
//             if(c[i]!=v[i]){
//                 c[i]=v[i];
//             }
//         }
//         return;
//     }
// };

class Solution {
public:
    
        TreeNode* first;
        TreeNode* prev;
        TreeNode* middle;
        TreeNode* last;

    void inorder(TreeNode* &root){
        if(root==NULL) return ;
        inorder(root->left);
        if(prev!=NULL && (root->val < prev->val)){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
            
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)  return;
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
        swap(first->val,last->val);
        else if(first && middle)
        swap(first->val,middle->val);
        
    }
};