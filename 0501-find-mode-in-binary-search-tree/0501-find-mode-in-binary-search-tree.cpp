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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> findMode(TreeNode* root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        inorder(root, ans);

        unordered_map<int, int> mp;

        for (int x : ans) {
            mp[x]++;
        }

        int maxCount = 0;

        // Find maximum frequency
        for (auto x : mp) {
            maxCount = max(maxCount, x.second);
        }

        vector<int> ans1;

        // Find ALL elements having maximum frequency
        for (auto x : mp) {
            if (x.second == maxCount) {
                ans1.push_back(x.first);
            }
        }

        return ans1;
    }
};




// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int>&ans){
//         if(root==NULL) return;
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//         return;
//     }
//     vector<int> findMode(TreeNode* root) {
//         vector<int>ans;
//         if(root==NULL){
//             return ans;
//         }
//         inorder(root,ans);
//         unordered_map<int, int> mp;

//         for (int x : ans) {
//         mp[x]++;
//         }

//         int maxElement = ans[0];
//         int maxCount = 0;

//         for (auto x : mp) {
//         if (x.second > maxCount) {
//         maxCount = x.second;
//         maxElement = x.first;
//         }
//         }
//         vector<int>ans1;
//         ans1.push_back(maxElement);
//         return ans1;
//     }
// };