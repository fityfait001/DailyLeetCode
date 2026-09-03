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
    int minDepth(TreeNode* root) {
        int height=1;
        if(root==NULL)
            return 0;
        if(root->left==NULL) return height+minDepth(root->right);
        if(root->right==NULL) return height+minDepth(root->left);
        
        return height+min(minDepth(root->left),minDepth(root->right));
        
    }
};