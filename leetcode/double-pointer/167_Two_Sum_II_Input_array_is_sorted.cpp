/* 题目描述：在有序数组中找出两个数，使它们的和为 target。 */

#include <utility>
#include <vector>
using std::pair;

typedef pair<int, int> res_idx;

res_idx two_sum(std::vector<int> nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r) {
	int sum = (nums[l]+nums[r]) / 2;
	if (sum == target)
	    return {l, r};
	else if (sum < target)
	    l++;
	else
	    r--;
    }

    return {-1, -1};
}
