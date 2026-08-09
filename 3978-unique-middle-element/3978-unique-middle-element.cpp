class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int middle=nums.size()/2;
        int val=nums[middle];
        nums.erase(nums.begin()+middle);
        if(find(nums.begin(),nums.end(),val)!=nums.end()){
            return false;
        }
        return true;
    }
};