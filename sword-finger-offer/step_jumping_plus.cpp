/* 一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级... 它也可以跳上 n 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。 */

#include <math.h>
#include <vector>
#include <cmath>
using std::vector;

int step_jumping_plus(int n)
{
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
	for (int j = 0;j < i;++j) {
	    dp[i] += dp[j];
	}
    }

    return dp[n-1];
}

int step_jumping_plus_math(int n)
{
    return pow(2, n-1);
}
