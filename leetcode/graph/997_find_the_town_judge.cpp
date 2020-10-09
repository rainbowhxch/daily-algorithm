#include <vector>

using std::vector;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trust_cnt(N+1, 0);

        for (auto i : trust) {
            trust_cnt[i[0]]--;
            trust_cnt[i[1]]++;
        }

        for (int i = 1;i <= N;++i) {
            if (trust_cnt[i] == N-1)
                return i;
        }

        return -1;
    }
};
