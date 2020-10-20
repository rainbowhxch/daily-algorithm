#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int SIZE_CNT = 10001;
        vector<int> cnt_nums(SIZE_CNT, 0);

        for (const auto &i : nums)
            cnt_nums[i]++;

        int tmp_sum = 0;
        for (int i = SIZE_CNT-1;i >= 0;--i) {
            tmp_sum += cnt_nums[i];
            if (tmp_sum == i)
                return i;
        }

        return -1;
    }
};
