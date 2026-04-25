#include <iostream>
#include <vector>
using namespace std;



int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int num : nums) sum += num;

   
    if (abs(target) > sum || (sum + target) % 2 != 0)
        return 0;

    int subsetSum = (sum + target) / 2;

    vector<int> dp(subsetSum + 1, 0);
    dp[0] = 1;

    for (int num : nums) {
        for (int j = subsetSum; j >= num; --j) {
            dp[j] += dp[j - num];
        }
    }

    return dp[subsetSum];
}

int main() {
    vector<int> nums = {1, 1, 1,1,1 };
    int target = 3;

    cout << "Number of ways = "
         << findTargetSumWays(nums, target)
         << endl;

    return 0;
}
