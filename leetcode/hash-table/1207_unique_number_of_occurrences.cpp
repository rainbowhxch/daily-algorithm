#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::unordered_map;
using std::unordered_set;

bool work(const vector<int> &arr) {
	unordered_map<int, int> m;
	unordered_set<int> s;
	for (const auto &i : arr)
		m[i]++;

	for (const auto &i : m)
		s.insert(i.second);

	return s.size() == m.size();
}
