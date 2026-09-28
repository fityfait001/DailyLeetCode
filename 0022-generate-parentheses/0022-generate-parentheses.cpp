
class Solution {
public:
    vector<string> ans;

    // bool isvalide(string &s){
    //     int i = 0;

    //     for(int j = 0; j < s.size(); j++){
    //         if(s[j] == '(')
    //             i++;
    //         else
    //             i--;

    //         if(i < 0)
    //             return false;
    //     }

    //     return i == 0;
    // }

    void solve(string &s, int n,int open,int close){
        if(s.size() == 2*n){
            
            ans.push_back(s);
            
            return;
        }
        if(open<n){
            s.push_back('(');
            solve(s,n,open+1,close);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            solve(s,n,open,close+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        int open=0;
        int close=0;
        solve(s,n,open,close);
        return ans;
    }
};