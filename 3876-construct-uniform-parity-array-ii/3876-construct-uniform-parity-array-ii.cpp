class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //Pehle nikalege smallest odd number
        int minOdd=INT_MAX;
        for(int x:nums1){
            if(x%2!=0){
                minOdd=min(minOdd,x);
            }
        }
        if(minOdd==INT_MAX){
            return true;
        }
        //Ab simple ye dekh lenge ki jo odd humne dhoondha hai wo kya smallest hai from every fucking even number and if it is not then what we have to do is we can subtract it with the even number its simple as fuck

        for(int x: nums1){
            if(x%2==0 && minOdd>x){
                return false;
            }
        }
        return true;
    }
};