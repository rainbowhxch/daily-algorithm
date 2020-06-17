#include <type_traits>
#include <vector>
using std::vector;

typedef vector<int> m_array;

bool is_even(int n)
{
    return !(n & 1);
}

m_array reorder_array(m_array nums)
{
    int odd_cnt = 0;
    for (auto i : nums) {
	if (is_even(i))
	    odd_cnt++;
    }

    m_array res = nums;
    int odd_idx = 0, even_idx = odd_cnt;
    for (auto i : nums) {
	if (is_even(i))
	    res[even_idx++] = i;
	else
	    res[odd_idx++] = i;
    }

    return res;
}

m_array reorder_array_bull(m_array nums)
{
    for (int i = nums.size()-1;i > 0;--i) {
	for (int j = 0;j < i;++j) {
	    if (is_even(nums[j]) && !is_even(nums[j+1])) {
		int tmp = nums[j];
		nums[j] = nums[j+1];
		nums[j+1] = tmp;
	    }
	}
    }

    return nums;
}
