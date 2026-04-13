#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int result = 0;

    for (int i = 0; i < n; i++) {
        map<pair<int,int>, int> slopeCount;
        int overlap = 0, currMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            // same point (though given unique, safe check)
            if (dx == 0 && dy == 0) {
                overlap++;
                continue;
            }

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            slopeCount[{dy, dx}]++;
            currMax = max(currMax, slopeCount[{dy, dx}]);
        }

        result = max(result, currMax + overlap + 1);
    }

    return result;
}

int main() {
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};
    cout << maxPoints(points) << endl; // Output: 3
    return 0;
}