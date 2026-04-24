#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void build(int node, int start, int end, vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;

        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);

        return left + right;
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node + 1, start, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, end, idx, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int rangeQuery(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void pointUpdate(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
};