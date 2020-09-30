#include <string>

using std::string;

class Solution {
public:
    string sortString(string s) {
		const int SIZE_ALP = 26;
		string res = "";
		int cnt[SIZE_ALP] = {0};

		for (auto c : s)
			cnt[c-'a']++;

		while (res.length() != s.length()) {
			for (int i = 0;i < SIZE_ALP;++i) {
				if (cnt[i] > 0) {
					res += i + 'a';
					cnt[i]--;
				}
			}

			for (int i = SIZE_ALP-1; i >= 0;--i) {
				if (cnt[i] > 0) {
					res += i + 'a';
					cnt[i]--;
				}
			}
		}

		return res;
    }
};
