#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> newArr(n);

    for (int i = 0; i < n; i++) {
        newArr[i] = arr[n - i - 1];
    }

    return newArr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> result = reverseArray(arr);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}