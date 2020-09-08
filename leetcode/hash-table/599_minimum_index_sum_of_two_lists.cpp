#include <cstdint>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::string;

vector<string> work(const vector<string> &list1, const vector<string> &list2) {
	unordered_map<string, int> m;
	vector<string> ans;
	int min_sum = INT32_MAX;

	for (int i = 0;i < list1.size();++i) {
		m[list1[i]] = i;
	}

	for (int i = 0;i < list2.size() && i <= min_sum;++i) {
		if (m.find(list2[i]) != m.end()) {
			int tmp_sum = m[list2[i]] + i;
			if (tmp_sum < min_sum) {
				min_sum = tmp_sum;
				ans.clear();
				ans.emplace_back(list2[i]);
			} else if (tmp_sum == min_sum) {
				ans.emplace_back(list2[i]);
			}
		}
	}

	return ans;
}
