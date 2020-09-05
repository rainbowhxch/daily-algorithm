#include <string>
#include <vector>

using std::vector;
using std::string;

#define SIZE_ALP 26

int work(const vector<string> &words, string chars) {
	int ans = 0;
	int cnt[SIZE_ALP] = {0};
	for (const auto &c : chars)
		cnt[c-'a']++;
	for (const auto &i : words) {
		int tmp_cnt[SIZE_ALP] = {0};
		for (const auto &j : i)
			tmp_cnt[j-'a']++;

		bool is_good = true;
		for (int k = 0;k < SIZE_ALP;++k) {
			if (tmp_cnt[k] > cnt[k]) {
				is_good = false;
				break;
			}
		}

		if (is_good)
			ans += i.size();
	}

	return ans;
}
