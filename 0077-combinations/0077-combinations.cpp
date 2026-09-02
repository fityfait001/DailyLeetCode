class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> partialSubset;
        dfs(n, partialSubset, combinations, k);
        return combinations;
    }
private:
    void dfs(int n, vector<int>& partialSubset, vector<vector<int>>& combinations, int k) {
        if(0 == n) {
            if(partialSubset.size() == k)
                combinations.push_back(partialSubset);
        } else {
            //without nums[i]
            dfs(n-1,  partialSubset, combinations, k);

            //with nums[i]
            partialSubset.push_back(n);
            dfs(n-1,  partialSubset, combinations, k);
            partialSubset.pop_back();
        }
    }
};