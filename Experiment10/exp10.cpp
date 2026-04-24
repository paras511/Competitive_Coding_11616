#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<pair<int, int>>& nums, int left, int mid, int right,
               vector<int>& count) {
        vector<pair<int, int>> temp;
        int i = left;
        int j = mid + 1;
        int smallerCount = 0;

        while (i <= mid && j <= right) {
            if (nums[i].first > nums[j].first) {
                smallerCount++;
                temp.push_back(nums[j]);
                j++;
            } else {
                count[nums[i].second] += smallerCount;
                temp.push_back(nums[i]);
                i++;
            }
        }

        while (i <= mid) {
            count[nums[i].second] += smallerCount;
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
    }

    void mergeSort(vector<pair<int, int>>& nums, int left, int right,
                   vector<int>& count) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);
        merge(nums, left, mid, right, count);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;
        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            indexedNums.push_back({nums[i], i});
        }

        mergeSort(indexedNums, 0, n - 1, count);
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 6, 1};

    vector<int> result = sol.countSmaller(nums);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}