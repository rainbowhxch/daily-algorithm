#include <vector>

using std::vector;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        const int SIZE_BOOK = 60;
        int ans = 0, cnt[SIZE_BOOK+1] = {0};

        for (const auto &i : time) {
            int mod = i % 60;
            ans += cnt[(60-mod)%60];
            cnt[mod]++;
        }

        return ans;
    }
};
