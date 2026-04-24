#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cntBits(vector<int> &A) {
        const long long MOD = 1000000007;
        long long n = A.size();
        long long ans = 0;

        // Check each bit position
        for (int bit = 0; bit < 32; bit++) {
            long long countSet = 0;

            // Count numbers having current bit set
            for (int num : A) {
                if (num & (1LL << bit)) {
                    countSet++;
                }
            }

            long long countUnset = n - countSet;

            // Contribution of this bit
            ans = (ans + (countSet * countUnset) % MOD) % MOD;
        }

        // Multiply by 2 because (i,j) and (j,i) are both counted
        return (2 * ans) % MOD;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Solution sol;
    cout << sol.cntBits(A) << endl;

    return 0;
}