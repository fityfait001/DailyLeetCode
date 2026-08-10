// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         list<int>findNge(arr[])
//         stack<int>st;
//         int n=nums.size();
//         st.push(nums[n-1]);
//         for(int i=2*n-1;i>=0;i--){
//             while(!st.empty() && st.top()<=nums[i%n])
//             st.pop();
//             if(nums[i]<n)

//             st.push(nums[i]);
//             else if(nums[])
//         }
//     }
// };



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        
        return nge;
    }
};