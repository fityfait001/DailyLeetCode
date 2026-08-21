class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxprofit=0;
        for(auto x: prices){
            mini=min(x,mini);
            maxprofit=max(maxprofit,x-mini);
        }
        return maxprofit;
    }
};