class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' && !s1.empty()){
                s1.pop();
            }
            else if(s[i]=='#' && s1.empty()){
                continue;
            }
            else
            s1.push(s[i]);
        }
        for(int j=0;j<t.size();j++){
            if(t[j]=='#' && !s2.empty()){
                s2.pop();
            }
            else if(t[j]=='#' && s2.empty()){
                continue;
            }
            else
            s2.push(t[j]);
        }
        if(s1==s2){
            return true;
        }
        return false;
    }
};