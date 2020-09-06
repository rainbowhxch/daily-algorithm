#include <algorithm>
#include <string>

using std::string;

#define SIZE_ALP 26

int work(string text) {
	int owned_alp[SIZE_ALP] = {0};
	int once_alp[SIZE_ALP] = {0};
	string des = "balloons";
	int ans = 0;

	for (const auto &c : des)
		once_alp[c-'a']++;
	for (const auto &c : text)
		once_alp[c-'a']++;

	if (once_alp[0] == 0)
		ans = 0;
	else
		ans = owned_alp[0] / once_alp[0];

	for (int i = 1;i < SIZE_ALP;++i)
		ans = std::min(ans, owned_alp[i]/once_alp[i]);

	return ans;
}
