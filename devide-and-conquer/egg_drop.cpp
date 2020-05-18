#include <bits/stdc++.h>
using namespace std;

int egg_drop(int n, int k)
{
    vector<std::vector<int> > dp(n+1, vector<int>(k+1, 0));
    for (int i = 1;i <= n;++i)
        dp[i][1] = i;
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= k;++j) {
            for (int z = 1;z <= i;++z)
                dp[i][j] = min(dp[i][j], max(dp[z-1][j-1], dp[n-z][j]));
        }
    }
}
