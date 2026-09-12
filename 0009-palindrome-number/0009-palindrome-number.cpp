class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x>pow(2,31)-1)
        return false;
        int l=x;
        long sum=0;
        while(x){
            int s=x%10;
            sum=sum*10+s;
            x=x/10;
        }
        if(l==sum)
        return true;
        else return false;   
    }
};