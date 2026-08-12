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
    vector<int> Morris_Inorder(TreeNode* root){
        vector<int>ans;
        if(root==NULL)
        return ans;
        TreeNode * curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* pred=curr->left;
                while(pred->right!=NULL && pred->right!=curr)
                pred=pred->right;

                if(pred->right==NULL)//left is not visited yet
                {
                    pred->right=curr;
                    curr=curr->left;
                }
                else{//left is visited before
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        return Morris_Inorder(root);


        // stack<TreeNode*>st;
        // TreeNode* node=root;
        // vector<int> inorder;
        // while(true){
        //     if(node!=NULL){
        //         st.push(node);
        //         node=node->left;
        //     }
        //     else{
        //         if(st.empty()==true) break;
        //         node=st.top();
        //         st.pop();
        //         inorder.push_back(node->val);
        //         node=node->right;
        //     }
        // }
        // return inorder;
        
    }
};