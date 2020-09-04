#include <vector>

using std::vector;

#define MAX_NUM 100

vector<int> work(const vector<int> &nums) {

	int cnt[MAX_NUM+1] = {0};
	for (const auto &i : nums) {
		cnt[i]++;
	}

	int less_cnt[MAX_NUM+1] = {0};
	for (int i = 1;i < MAX_NUM+1;++i) {
		less_cnt[i] = less_cnt[i-1] + cnt[i-1];
	}

	vector<int> ans;
	for (const auto &i : nums) {
		ans.emplace_back(less_cnt[i]);
	}

	return ans;
}
