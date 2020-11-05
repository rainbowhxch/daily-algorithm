#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res, sum = 0;
        for (int i = 0;i < k;++i)
            sum += nums[i];

        res = sum;
        for (int i = k;i < nums.size();++i) {
            sum += nums[i] - nums[i-k];
            res = max(res, sum);
        }

        return res/k;
    }
};
