#include <unordered_set>
#include <cmath>

using std::unordered_set;

bool is_happy(int n) {
	unordered_set<int> s;

	while (s.find(n) == s.end()) {
		s.insert(n);

		int tmp_sum = 0;
		while (n > 0) {
			tmp_sum += std::pow(n%10, 2);
			n /= 10;
		}

		if (tmp_sum == 1)
			return true;
		n = tmp_sum;
	}

	return false;
}
