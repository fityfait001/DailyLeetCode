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
    
//     bool isCompleteTree(TreeNode* root) {
//         //using bfs
//         bool past=false;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode * node=q.front();
//             q.pop();
//             if(node==NULL){
//                 past=true;
//             }
//             else{
//                 if(past==true)
//                 return false;

//                 q.push(node->left);
               
//                 q.push(node->right);
//             }

//         }
        
//         return true;
//     }
// };

//using DFS
class Solution {
public:
    int countNodes(TreeNode* root){
        if(root==NULL)
        return 0;

        return 1+countNodes(root->left)+countNodes(root->right);
    }

    bool dfs(TreeNode* root,int i,int totalNodes){
        if(root==NULL)
        return true;

        if(i>totalNodes)
        return false;

        return dfs(root->left,2*i,totalNodes) &&
               dfs(root->right,2*i+1,totalNodes);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNodes=countNodes(root);
        int i=1;
        return dfs(root,i,totalNodes);
    }
};