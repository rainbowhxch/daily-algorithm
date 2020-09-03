#include <cstring>
#include <cmath>

int divisor_game(int N) {
	bool dp[N+1];
	memset(dp, false, sizeof dp);

	for (int i = 2;i <= N;++i) {
		for (int j = 1;j < sqrt(i);++j) {
			if (i % j == 0 && !dp[i-j]) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[N];
}
