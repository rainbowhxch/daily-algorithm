#include <algorithm>
#include <vector>

using std::vector;
using std::sort;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;

        for (int i = 0, j = 0;i < g.size() && j < s.size(); ) {
            if (g[i] <= s[j]) {
                cnt++;
                i++;
            }

            j++;
        }

        return cnt;
    }
};
