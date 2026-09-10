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
    int ans=0;
    void avg(TreeNode* root,vector<int>&res){
        if(root==NULL)
        return ;
        vector<int>l(2,0);
        vector<int>r(2,0);

        avg(root->left,l);
        avg(root->right,r);

        
        int avvg=(l[0]+r[0]+root->val)/(l[1]+r[1]+1);
        if(avvg==root->val){
            ans++;
        }
        res[0]=(l[0]+r[0]+root->val);
        res[1]=(l[1]+r[1]+1);
    }


    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr)
        return ans;
        vector<int>res(2);
        avg(root,res);
        return ans;
        
    }
};