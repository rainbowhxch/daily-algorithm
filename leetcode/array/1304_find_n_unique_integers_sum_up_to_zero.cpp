#include <vector>

using std::vector;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        if (n & 1)
            ans.emplace_back(0);
        for (int i = 1;i <= n/2;++i) {
            ans.emplace_back(i);
            ans.emplace_back(-i);
        }

        return ans;
    }
};
