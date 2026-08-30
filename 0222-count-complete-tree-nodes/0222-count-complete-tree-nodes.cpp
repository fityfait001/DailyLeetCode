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
    int getLeftNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        else return 1+getLeftNodes(root->left);
    }
    int getRightNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        else return 1+getRightNodes(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root)
        return 0;
        int lh=getLeftNodes(root);
        int rh=getRightNodes(root);
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    //     if(root==NULL){
    //         return 0;
    //     }
    //     return 1+countNodes(root->left)+countNodes(root->right);
    }
};