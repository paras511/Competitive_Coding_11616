class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++){
            v.push_back({nums[i], i});
        }

        mergeSort(v, 0, n - 1, ans);
        return ans;
    }

    void mergeSort(vector<pair<int,int>>& v, int l, int r, vector<int>& ans) {
        if(l >= r) return;

        int mid = (l + r) / 2;
        mergeSort(v, l, mid, ans);
        mergeSort(v, mid + 1, r, ans);
        merge(v, l, mid, r, ans);
    }

    void merge(vector<pair<int,int>>& v, int l, int mid, int r, vector<int>& ans) {
        vector<pair<int,int>> temp;
        int i = l, j = mid + 1;
        int rightCount = 0;

        while(i <= mid && j <= r){
            if(v[j].first < v[i].first){
                rightCount++;
                temp.push_back(v[j++]);
            } else {
                ans[v[i].second] += rightCount;
                temp.push_back(v[i++]);
            }
        }

        while(i <= mid){
            ans[v[i].second] += rightCount;
            temp.push_back(v[i++]);
        }

        while(j <= r){
            temp.push_back(v[j++]);
        }

        for(int k = l; k <= r; k++){
            v[k] = temp[k - l];
        }
    }
};