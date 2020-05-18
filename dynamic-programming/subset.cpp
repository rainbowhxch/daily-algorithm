#include <bits/stdc++.h>
using namespace std;

bool can_partition(vector<int> nums)
{
    int sum = 0;
    for (auto i : nums)
        sum += i;
    if (sum % 2 != 0) return false;
    sum /= 2;
    bool *dp = new bool[nums.size()];
    dp[0] = true;
    for (int i = 1;i < nums.size();++i)
        dp[i] = false;
    for (int i = 0;i < sum;++i) {
        for (int j = 0;j < nums.size();++j) {
            if (i > nums[j])
                dp[i] = dp[i] || dp[i - nums[j]];
        }
    }

    return dp[sum];
}
