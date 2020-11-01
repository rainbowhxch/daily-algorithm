#include <vector>

using std::vector;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left_sum = 0;

        for (const auto &i : nums)
            sum += i;

        for (int i = 0;i < nums.size();++i) {
            if (sum - left_sum - nums[i] == left_sum)
                return i;
            left_sum += nums[i];
        }

        return -1;
    }
};
