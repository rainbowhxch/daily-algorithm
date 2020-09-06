#include <vector>

using std::vector;

#define SIZE_NUM 2000 + 1
#define FAILED -1

int work(const vector<int> &arr, int k) {
	int cnt[SIZE_NUM] = {0};
	for (const auto &i : arr)
		cnt[i]++;

	int index = 0;
	for (int i = 1;i < SIZE_NUM;++i) {
		if (cnt[i] == 0)
			index++;
		if (index == k)
			return i;
	}

	return FAILED;
}
