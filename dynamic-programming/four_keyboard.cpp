#include <vector>

using std::vector;

int four_keyboard(int n)
{
    int *dp = new int[n+1];
    dp[0] = 0;
    for (int i = 1;i <= n;++i) {
        dp[i] = dp[i-1] + 1;
        for (int j = 2;j < i;++j) {
            dp[i] = std::max(dp[i], dp[j-2] * (i-j+1));
        }
    }

    return dp[n];
}
