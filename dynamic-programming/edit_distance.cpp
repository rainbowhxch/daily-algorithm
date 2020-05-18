#include <bits/stdc++.h>
using namespace std;

int _min(int a, int b, int c)
{
    return min(a, min(b, c));
}

int min_edit_distance(string a, string b)
{
    vector<vector<int> > dp(a.size()+1, vector<int>(b.size()+1, 0));
    for (int i = 0;i <= a.size();++i)
        dp[i][0] = i;
    for (int i = 0;i <= b.size();++i)
        dp[0][i] = i;
    for (int i = 1;i <= a.size();++i) {
        for (int j = 1;j <= b.size();++j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = _min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
        }
    }

    return dp[a.size()][b.size()];
}
