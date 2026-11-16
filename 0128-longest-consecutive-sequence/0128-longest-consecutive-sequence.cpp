class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int>st;
      for (int n:nums){
        st.insert(n);
      } 
      int ans=0;
      int count; 

      for(int i:st){
        if(st.find(i-1)==st.end()){
            int curr=i;
            count=1;


            while(st.find(curr+1)!=st.end()){
                curr++;
                count++;
            }
            ans=max(ans,count);
        }
        
      }
      return ans;
    }
};