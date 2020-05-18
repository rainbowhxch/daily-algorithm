#include <bits/stdc++.h>
#include <vector>
using namespace std;

int egg_drop(int n, int k)
{
    vector<vector<int> > dp(k+1, vector<int>(n+1, 0));
    int m = 1;
    while (dp[k][m] < n) {
        m++;
        for (int i = i;i <= k;++i)
            dp[i][m] = dp[i-1][m-1] + dp[i][m-1] + 1;
    }

    return m;
}
