#include <algorithm>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt = 0;
        unordered_map<int, int> m;

        for (const auto &i : dominoes)
            cnt += m[max(i[0], i[1])*10 + min(i[0], i[1])]++;

        return cnt;
    }
};
