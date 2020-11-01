#include <vector>
#include <limits.h>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (const auto &i : nums) {
            if (i <= min1) {
                min1 = i;
                min2 = min1;
            } else if (i <= min2) {
                min2 = i;
            }

            if (i >= max1) {
                max1 = i;
                max2 = max1;
                max3 = max2;
            } else if (i >= max2) {
                max2 = i;
                max3 = max2;
            } else if (i >= max3) {
                max3 = i;
            }
        }

        return max(max1*min1*min2, max1*max2*max3);
    }
};
