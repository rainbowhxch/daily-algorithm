#include <vector>

using std::vector;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int start = rounds[0], end = rounds[rounds.size()-1];
        if (start > end) {
            for (int i = 1;i <= end;++i)
                ans.push_back(i);
            for (int i = start;i <= n;++i)
                ans.push_back(i);
        } else {
            for (int i = start;i <= end;++i)
                ans.push_back(i);
        }

        return ans;
    }
};
