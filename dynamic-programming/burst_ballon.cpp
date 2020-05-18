#include <bits/stdc++.h>
using namespace std;

int burst_ballon(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int> > dp(n+2, vector<int>(n+2, 1));
    vector<int> tmp(n+2);
    tmp.push_back(0);
    for (auto i : nums) {
        tmp.push_back(i);
        tmp.push_back(0);
    }
    for (int i = n;i >= 0;i--) {
        for (int j = i+1;j <= n+1;++j) {
            for (int k = i+1;k <= j-1;k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + tmp[i] * tmp[k] * tmp[j]);
            }
        }
    }

    return dp[0][n+1];
}
