#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::min;
using std::max_element;
using std::numeric_limits;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
		constexpr int N = 41;
		vector<vector<int>> dp(N, vector<int>(N, -1));
		return solve(arr, 0, arr.size()-1, dp);
    }
private:
	int solve(const vector<int> &arr, int left, int right, vector<vector<int>> &dp) {
		if (left == right)
			return 0;
		if (dp[left][right] != -1)
			return dp[left][right];

		int ans = numeric_limits<int>::max();
		for (int mid = left; mid < right; ++mid) {
			ans = min(ans, solve(arr, left, mid, dp) + solve(arr, mid+1, right, dp) +
					*max_element(arr.begin()+left, arr.begin()+mid+1) * *max_element(arr.begin()+mid+1, arr.begin()+right+1));
		}

		return dp[left][right] = ans;
	}
};
