class Solution {
public:
    int rev(int x) {
    int ans = 0;

    while(x > 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }

    return ans;
}
   int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long count=0;
        long long mod=1000000007;
        for(int x:nums){
            int key=x-rev(x);
            count=(count+mp[key])%mod;
            mp[key]++;
        }
        return count;
    }
};
// TLE
//     int countNicePairs(vector<int>& nums) {
//         if(nums.size()==0){
//             return 0;
//         }
//         int count=0;
        
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+rev(nums[j])==nums[j]+rev(nums[i])){
//                     count++;
//                 }
//             }
//         }
//         return count%1000000007;
//     }
// };