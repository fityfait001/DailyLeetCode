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
    int sum=0;
    int sumofnodes(TreeNode* root){
        if(root==NULL) return 0;
        int left=sumofnodes(root->left);
        int right=sumofnodes(root->right);
        sum+=abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        sumofnodes(root);
        return sum;
    }
};