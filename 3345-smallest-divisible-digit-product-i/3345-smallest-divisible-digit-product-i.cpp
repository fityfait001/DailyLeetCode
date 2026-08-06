class Solution {
public:
    // int product(int n){
    //     int product1=1;
    //     while(n>0){
    //         int x=n%10;
    //         product1=product1*x;
    //         n=n/10; 
    //     }
    //     return product1;
    // }
    int smallestNumber(int n, int t) {
        // int y=n;
        
        // while(true){
        //     if(product(y)%t==0)
        //     return y;
    
        //     y++;
        
        
        // }
        // return y;
        while(true){
            string a=to_string(n);
            int product=1;
            for(int i=0;i<a.size();i++){
                product*=int(a[i]-'0');
            }
            if(product%t==0)
            return n;
            n++;
        }
        return n;
        
    }
};