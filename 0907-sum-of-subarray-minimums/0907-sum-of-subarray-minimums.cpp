class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       

        // T L E
        // int sum=0;
        // int mod=1e9+7;
        // for(int i=0;i<arr.size();i++){
        //     int mini=arr[i];
        //     for(int j=i;j<arr.size();j++){
        //         mini=min(mini,arr[j]);
        //         sum=(sum+mini)%mod;
        //     }
        // }
        // return sum;

        int n=arr.size();
        long long ans=0;
        int mod=1e9+7;
        stack<int>st;
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            left[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            right[i]=st.empty() ? n: st.top();
            st.push(i);
        }

        //Contribution calculation
        for(int i=0;i<n;i++){
            long long leftCount=i-left[i];
            long long rightCount=right[i]-i;
            ans=(ans+arr[i]*leftCount*rightCount)%mod;
        }
        return ans;

    }
};