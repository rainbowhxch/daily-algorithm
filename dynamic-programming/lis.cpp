#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> nums)
{
    int res = 0;
    int *dp = new int[nums.size()];
    for (int i = 0;i < nums.size();++i)
        dp[i] = 1;
    for (int i = 0;i < nums.size();++i) {
        for (int j = 0;j < i;++j) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = 0;i < nums.size();++i)
        res = max(res, dp[i]);
    return res;
}

int main()
{
    cout << lis({2, 1, 4, 5, 1});
    return 0;
}
