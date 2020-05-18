#include <bits/stdc++.h>

using namespace std;

int charge(int amount, vector<int> coins)
{
    int *dp = new int[coins.size()];
    dp[0] = 1;
    for (int i = 1;i < amount;++i) {
        for (int j = 1;j < coins.size();++j) {
            if (i >= coins[j]) dp[i] = dp[i-coins[j]];
        }
    }
    return dp[amount];
}
