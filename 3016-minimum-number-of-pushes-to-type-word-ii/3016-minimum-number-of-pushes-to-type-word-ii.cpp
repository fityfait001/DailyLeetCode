class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char x:word){
            freq[x-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int cost=0;
        int p=1;
        int temp=1;
        // for(auto x:freq){
        //     cost+=x*p;
        //     temp++;
        //     if(temp%8==0){
        //         p++;
        //     }
        // }
        for(int i = 0; i < 26; i++){
    cost += freq[i] * (i / 8 + 1);
}
        return cost;


    }
};