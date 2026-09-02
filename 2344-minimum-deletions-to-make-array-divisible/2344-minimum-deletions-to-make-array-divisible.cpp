class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
       int g=numsDivide[0];
       for(int i:numsDivide){
           g= gcd(i,g);
       }
       sort(nums.begin(),nums.end());
       int dele=0;
       for(auto i:nums){
        if(g%i==0){
            return dele;
        }
        else
        dele++;
       }
       return -1;
    }
};