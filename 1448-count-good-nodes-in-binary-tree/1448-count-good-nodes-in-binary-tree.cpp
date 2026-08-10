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
    int goodNodeCount=1;
    int goodNodes(TreeNode* root) {
        getGoodNodes(root->left,root->val);
        getGoodNodes(root->right,root->val);
        return goodNodeCount;
    }
    void getGoodNodes(TreeNode* root,int grtNum){
        if(root==NULL) return;
        if(root->val>=grtNum){
            goodNodeCount++;
        }
        grtNum=max(grtNum,root->val);
        getGoodNodes(root->left,grtNum);
        getGoodNodes(root->right,grtNum);
    }
};