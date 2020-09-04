#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

int work(const vector<int> &nums) {
	unordered_map<int, int> items;
	int pairs_cnt = 0;

	for (const auto &i : nums) {
		if (items.find(i) == items.end()) {
			items[i] = 1;
		} else {
			items[i]++;
		}
	}

	for (const auto &item : items) {
		pairs_cnt += (item.second-1) * item.second / 2;
	}

	return pairs_cnt;
}
