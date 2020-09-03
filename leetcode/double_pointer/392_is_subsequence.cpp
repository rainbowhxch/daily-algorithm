#include <bits/c++config.h>
#include <string>

using std::string;

bool is_subsequence(string s, string t) {
	std::size_t s_ptr = 0, t_ptr = 0;

	while (s_ptr < s.size() && t_ptr < t.size()) {
		if (s[s_ptr] == t[t_ptr])
			s_ptr++;
		t_ptr++;
	}

	return s_ptr == s.size();
}
