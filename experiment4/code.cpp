#include <iostream>
#include <vector>
using namespace std;

int ex4(vector<int>& arr) {
    const int mod = 1e9 + 7;
    long long ans = 0;

    for (int i = 0; i < 32; i++) {
        long long countSet = 0;
        long long countUnset = 0;

        for (int j = 0; j < arr.size(); j++) {
            if ((arr[j] & (1 << i)) != 0) {
                countSet++;
            } else {
                countUnset++;
            }
        }

        ans = (ans + (countSet % mod) * (countUnset % mod) % mod) % mod;
    }

    return (ans * 2) % mod;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Sum of bit differences of all pairs: " << ex4(arr) << endl;

    return 0;
}
