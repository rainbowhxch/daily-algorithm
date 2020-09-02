#include <algorithm>
#include <vector>

int maxSubArray(std::vector<int> &nums) {
	int max_sub = nums[0], cur_sub = 0;

	for (auto i : nums) {
		if (cur_sub < 0)
			cur_sub = 0;
		cur_sub += i;
		max_sub = std::max(max_sub, cur_sub);
	}

	return max_sub;
}
