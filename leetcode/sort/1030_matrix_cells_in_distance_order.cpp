#include <map>
#include <algorithm>
#include <utility>
#include <vector>

using std::vector;
using std::multimap;
using std::make_pair;
using std::abs;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int> > res;
        multimap<int, vector<int> > mm;

        for (int i = 0;i < R;++i) {
            for (int j = 0;j < C;++j) {
				mm.insert(make_pair<int, vector<int> >(abs(i-r0) + abs(j-c0), {i, j}));
            }
        }

		for (auto &i : mm)
			res.emplace_back(i.second);

		return res;
    }
};
