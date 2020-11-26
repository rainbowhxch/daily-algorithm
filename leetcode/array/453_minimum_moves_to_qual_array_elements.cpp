#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::min;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mmin = std::numeric_limits<int>::max(), sum = 0, ans = 0;
        for (const auto &i : nums) {
            mmin = min(mmin, i);
        }
        for (const auto &i : nums) {
            ans += i - mmin;
        }

        return ans;
    }
};
