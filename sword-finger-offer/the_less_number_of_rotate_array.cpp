/* 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 */

#include <vector>
using std::vector;

int less_number(vector<int> nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r) {
	int m = (l+r) / 2;
	if (nums[m] < nums[r]) {
	    r = m;
	} else {
	    l = m + 1;
	}
    }

    return nums[l];
}
