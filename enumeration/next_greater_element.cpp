#include <vector>
#include <stack>

using std::vector;
using std::stack;

vector<int> next_greater_element(vector<int> nums)
{
    vector<int> res(nums.size());
    stack<int> s;

    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[i] > s.top())
            s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }

    return res;
}
