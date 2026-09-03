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
class Solution {
public:
    // TreeNode* inorder(TreeNode* root,TreeNode* n1,TreeNode* n2){
    //     if(n1==NULL) return n1;
    //     inorder(root,n1->left,n2->right);
    //     int temp;
        
    //     temp=n1->val;
    //     n1->val=n2->val;
    //     n2->val=temp;
    //     inorder(root,n1->right,n2->left);
    //     return root;
    // }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
        return nullptr;
        
        TreeNode* temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;

        invertTree(root->left);
        invertTree(root->right);
        return root;
       
    }
};