#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int mmin = 1;

        for (const auto &i : nums) {
            sum += i;
            mmin = min(sum, mmin);
        }

        return mmin >= 1 ? 1 : 1-mmin;
    }
};
