#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int ans = 1, anchor = 0;

        for (int i = 1;i < nums.size();++i) {
            if (nums[i] <= nums[i-1]) {
                ans = max(ans, i - anchor);
                anchor = i;
            }
        }
        if (nums.size()-anchor > ans)
            ans = nums.size()-anchor;

        return ans;
    }
};
