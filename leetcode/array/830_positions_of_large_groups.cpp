#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int> > ans;
        int cnt = 1;

        for (int i = 1;i < s.size();++i) {
            if (s[i] == s[i-1]) {
                cnt++;
                if (i == s.size()-1 && cnt >= 3)
                    ans.push_back({i-cnt+1, i});
            } else {
                if (cnt >= 3)
                    ans.push_back({i-cnt, i-1});
                cnt = 1;
            }
        }

        return ans;
    }
};
