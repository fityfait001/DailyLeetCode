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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(root->left==NULL && root->right==NULL){
            return targetSum==root->val;
        }
        int remaining=targetSum-root->val;
        return hasPathSum(root->left,remaining) || hasPathSum(root->right,remaining);
    //     if(root==nullptr) return false;
    //     if (root->left==nullptr && root->right==nullptr){
    //         return targetSum==root->val;
    //     }
    //     int remainingSum=targetSum-root->val;
    //     return hasPathSum(root->left,remainingSum)||hasPathSum(root->right,remainingSum);
    }
};

// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         // If the tree is empty, there are no root-to-leaf paths
//         if (root == nullptr) {
//             return false;
//         }
        
//         // If it's a leaf node, check if its value matches the remaining target sum
//         if (root->left == nullptr && root->right == nullptr) {
//             return targetSum == root->val;
//         }
        
//         // Recursively check the left and right subtrees with the reduced target sum
//         int remainingSum = targetSum - root->val;
//         return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
//     }
// };