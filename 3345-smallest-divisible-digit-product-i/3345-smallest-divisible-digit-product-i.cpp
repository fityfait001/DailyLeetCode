class Solution {
public:
    int product(int n){
        int product1=1;
        while(n>0){
            int x=n%10;
            product1=product1*x;
            n=n/10; 
        }
        return product1;
    }
    int smallestNumber(int n, int t) {
        int y=n;
        
        while(true){
            if(product(y)%t==0)
            return y;
    
            y++;
        
        
        }
        return y;
        
    }
};