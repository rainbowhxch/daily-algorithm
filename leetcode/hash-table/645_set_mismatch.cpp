#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup, miss;
        for (auto n : nums) {
            if (nums[abs(n)-1] < 0)
                dup = abs(n);
            else
                nums[abs(n)-1] *= -1;
        }

        for (int i = 0;i < nums.size();++i)
            if (nums[i] > 0)
                miss = i + 1;

        return {dup, miss};
    }
};
