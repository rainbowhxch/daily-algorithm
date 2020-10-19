#include <vector>

using std::vector;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        const int SIZE_CNT = 501;
        int cnt[SIZE_CNT] = {0};

        for (const auto &i : arr)
            cnt[i]++;

        for (int i = 1;i < SIZE_CNT;++i) {
            if (i == cnt[i]) {
                ans = i;
            }
        }

        return ans;
    }
};
