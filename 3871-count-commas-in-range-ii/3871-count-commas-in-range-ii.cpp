class Solution {
public:
    long long countCommas(long long n) {
        long long count=0;
        long long p=1000;
        for(int i=1;i<6;i++){
            count=count + max(0LL,n - p + 1);
            p*=1000;
        }
        return count;
    }
};