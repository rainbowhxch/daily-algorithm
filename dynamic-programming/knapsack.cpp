#include <bits/stdc++.h>

using namespace std;

int knapsack(int w, int n, vector<int> &wt, vector<int> &val)
{
    vector<vector<int> > dp(n+1, vector<int>(w+1, 0));
    for (int i = 1;i < n;++i) {
        for (int j = 1;j < w;++j) {
            if (j - wt[i] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i]]+val[i]);
        }
    }

    return dp[n][w];
}
