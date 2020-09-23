#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int cur_idx = 0;

        for (int i = 1;i <= n;++i) {
            if (cur_idx == target.size())
                break;

            res.emplace_back("Push");
            if (i != target[cur_idx]) {
                res.emplace_back("Pop");
            } else {
                cur_idx++;
            }
        }

        return res;
    }
};
