#include <iostream>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int max_val = 0;
            int best = 0;

            for (int len = 1; len <= k && i + len <= n; len++) {
                max_val = max(max_val, arr[i + len - 1]);
                best = max(best, max_val * len + dp[i + len]);
            }

            dp[i] = best;
        }

        return dp[0];
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    cout << "Output 1: " << sol.maxSumAfterPartitioning(arr1, k1) << endl; // 84

    vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    cout << "Output 2: " << sol.maxSumAfterPartitioning(arr2, k2) << endl; // 83

    return 0;
}
