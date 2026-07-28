class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways=0;
        int min_c2,max_c2;
        for(int c1=0;c1<=min(n,limit);c1++){
            int rem=n-c1;
            min_c2=max(0,rem-limit);
            max_c2=min(rem,limit);
            if(min_c2<=max_c2){
            ways=ways+(max_c2-min_c2+1);
        }
        }
        // if(min_c2<=max_c2){
        //     ways=ways+(max_c2-min_c2+1);
        // }
        return ways;
    }
};