#include <algorithm>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

int find_LHS(const vector<int> &nums) {
	unordered_map<int, int> m;
	int res = 0;

	for (const auto &n : nums)
		m[n]++;
	for (const auto &i : m) {
		if (m.find(i.first+1) != m.end())
			res = std::max(res, m[i.first]+m[i.first+1]);
	}

	return res;
}
