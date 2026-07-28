// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         int n=s.size();
//         int mid=n/2;
//         for(int i=0;i<mid;i++){
//             sort(s.begin(), s.begin() + n / 2);
//         }
//         for(int i=0;i<mid;i++){
            
//             s[n-1-i]=s[i];
//         }
//         return s;
//     }
// };
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        // Sort only the left half
        sort(s.begin(), s.begin() + n / 2);

        // Mirror it
        for (int i = 0; i < n / 2; i++) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};