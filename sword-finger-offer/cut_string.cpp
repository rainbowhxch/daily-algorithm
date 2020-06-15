/* 把一根绳子剪成多段，并且使得每段的长度乘积最大。 */

#include <algorithm>
#include <vector>
using std::vector;
using std::max;

int cur_string(int n)
{
    vector<int> dp(n+1, 1);
    for (int i = 2;i <= n;++i) {
	for (int j = 1;j < i;++j) {
	    dp[i] = max(dp[i], max(j*(i-j), dp[j]*(i-j)));
	}
    }

    return dp[n];
}
