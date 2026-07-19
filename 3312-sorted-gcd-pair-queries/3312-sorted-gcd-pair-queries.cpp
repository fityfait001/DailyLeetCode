// int gcd(int a, int b) {
//     while (b) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }class Solution {
// public:
    
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         vector<long long >gcds;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 gcds.push_back(gcd(nums[i],nums[j]));
//             }
//         }
// //         int n = nums.size();
// // int i = 0, j = 1;

// // while (i < n - 1) {
// //     gcds.push_back(gcd(nums[i], nums[j]));

// //     j++;
// //     if (j == n) {
// //         i++;
// //         j = i + 1;
// //     }
// // }
//         vector<int> ans(queries.size());

// sort(gcds.begin(), gcds.end());

// for (int i = 0; i < queries.size(); i++) {
//     ans[i] = gcds[queries[i]];
// }

// return ans;
//     }
// };
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        // Step 1: Find maximum element
        int mx = *max_element(nums.begin(), nums.end());

        // Step 2: Frequency array
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // Step 3: cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // Step 4: exact[d] = pairs having gcd exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {

            // Total pairs divisible by d
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;

            // Remove pairs whose gcd is a multiple of d
            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        // Step 5: Prefix sum
        vector<long long> prefix(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exact[d];
        }

        // Step 6: Answer queries
        vector<int> ans;

        for (long long q : queries) {

            int gcdValue =
                lower_bound(prefix.begin(), prefix.end(), q + 1)
                - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};