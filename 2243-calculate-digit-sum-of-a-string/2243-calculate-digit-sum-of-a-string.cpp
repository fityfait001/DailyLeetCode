class Solution {
public:
    string digitSum(string s, int k) {
        string ans;
        
        while(s.size()>k){
            ans="";
            int i=0;
            while(i<s.size()){
                string temp=s.substr(i,k);
                int sum=0;

                for(int i=0;i<temp.size();i++){
                    sum+=temp[i]-'0';
                }
                ans+=to_string(sum);
                i+=k;
            }
            s=ans;
        }

        return s;
    }
};