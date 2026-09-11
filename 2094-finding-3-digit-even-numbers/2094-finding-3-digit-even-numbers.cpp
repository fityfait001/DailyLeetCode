class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        unordered_set<int>st;
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                if(i==j)
                continue;
                for(int k=0;k<digits.size();k++){
                    if(k==i || k==j)
                    continue;
                    int x=digits[i]*100+digits[j]*10+digits[k];
                    if(x%2==0 && digits[i]!=0){
                        st.insert(x);
                    }
                }
            }
        }
        vector<int>ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};