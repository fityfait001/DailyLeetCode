class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<int>ans;
       int min=nums[0];
       int max=nums[nums.size()-1];
       int x=min;
       for(int i=0;i<nums.size();i++){
        while(x<nums[i]){
            if(x!=nums[i]){
                ans.push_back(x);
            }
            x++;
        }
        x++;
       }
       return ans; 
    }
};