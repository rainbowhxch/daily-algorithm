#include <bits/stdc++.h>
#include <vector>
using namespace std;

int lcs(string a, string b)
{
    vector<vector<int> > dp(a.size()+1, vector<int>(b.size()+1, 0));
    for (int i = 1;i <= a.size();++i) {
        for (int j= 1;j <= b.size();++j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[a.size()][b.size()];
}
