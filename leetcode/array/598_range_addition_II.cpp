#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (const auto &i : ops) {
            m = min(i[0], m);
            n = min(i[1], n);
        }

        return m * n;
    }
};
