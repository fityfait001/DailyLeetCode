class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> merge(const vector<int>& vec1, const vector<int>& vec2) {
        vector<int> result;
        result.reserve(vec1.size() + vec2.size());
        
        int i = 0, j = 0;
        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] <= vec2[j]) {
                result.push_back(vec1[i++]);
            } else {
                result.push_back(vec2[j++]);
            }
        }
        
        while (i < vec1.size()) {
            result.push_back(vec1[i++]);
        }
        while (j < vec2.size()) {
            result.push_back(vec2[j++]);
        }
        
        return result;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);
        return merge(ans1, ans2);
    }
};