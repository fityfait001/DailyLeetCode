class Solution {
public:
    int minimumPushes(string word) {
        int s=word.size();
        int q=s/8;
        int i=1;
        int r=s%8;
        int count=0;
        // for(i;i<=q;i++){
        //     count=count+i*8;
        // }
        count=q*(q+1)*4+(q+1)*r;
        return count;
    }
};