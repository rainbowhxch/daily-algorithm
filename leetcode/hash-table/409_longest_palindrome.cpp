#include <string>

using std::string;

#define SIZE_ALP 128

int work(string s) {
	int cnt[SIZE_ALP] = {0};
	int ans = 0;

	for (const auto &c : s)
		cnt[c-'A']++;
	for (int i = 0;i < SIZE_ALP;++i) {
		ans += cnt[i] / 2 * 2;
		if (ans % 2 == 0 && cnt[i] % 2 == 1)
			ans += 1;
	}

	return ans;
}
