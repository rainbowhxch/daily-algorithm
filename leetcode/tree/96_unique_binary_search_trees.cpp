#include <vector>

using std::vector;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);

        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) { /* each of 2...n */
            for (int j = 1; j <= i; ++j) { /* the value of current root node */
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }
};
