#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cnt = 0;

        for (int i = 1;i < points.size();++i) {
            auto a = points[i-1];
            auto b = points[i];
            cnt += max(abs(a[0]-b[0]), abs(a[1]-b[1]));
        }

        return cnt;
    }
};
