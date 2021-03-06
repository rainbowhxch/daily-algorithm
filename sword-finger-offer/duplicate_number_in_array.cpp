/* 在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的，也不
知道每个数字重复几次。请找出数组中任意一个重复的数字。
要求时间复杂度 O(N)，空间复杂度 O(1)。 */

    /* Input:
    {2, 3, 1, 0, 2, 5}

    Output:
    2 */

#include <vector>
using std::vector;

void swap(vector<int> &nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

bool duplicate_number(vector<int> nums, int len)
{
    if (len <= 0)
	return false;

    for (int i = 0;i < len;++i) {
	while (nums[i] != i) {
	    if (nums[i] == nums[nums[i]])
		return true;
	    swap(nums, i, nums[i]);
	}
    }

    return false;
}
