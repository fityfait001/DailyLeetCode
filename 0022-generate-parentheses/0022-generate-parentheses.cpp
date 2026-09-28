
class Solution {
public:
    vector<string> ans;

    bool isvalide(string &s){
        int i = 0;

        for(int j = 0; j < s.size(); j++){
            if(s[j] == '(')
                i++;
            else
                i--;

            if(i < 0)
                return false;
        }

        return i == 0;
    }

    void solve(string &s, int n){
        if(s.size() == 2*n){
            if(isvalide(s)){
                ans.push_back(s);
            }
            return;
        }

        s.push_back('(');
        solve(s,n);
        s.pop_back();

        s.push_back(')');
        solve(s,n);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s,n);
        return ans;
    }
};