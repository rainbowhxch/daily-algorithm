#include <vector>
#include <functional>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
		vector<int> ans;
        int sum_nums = 0, sum_tmp = 0;

        for (auto i : nums)
            sum_nums += i;
		sum_nums /= 2;

		std::sort(nums.begin(), nums.end(), std::greater<int>());
		for (auto i : nums) {
			if (sum_tmp > sum_nums)
				break;

			sum_tmp += i;
			ans.emplace_back(i);
		}
		return ans;
    }
};
