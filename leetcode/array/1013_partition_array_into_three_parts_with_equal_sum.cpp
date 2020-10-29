#include <vector>
#include <numeric>

using std::vector;
using std::accumulate;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int part_sum = accumulate(A.begin(), A.end(), 0) / 3;
        int cur_sum = 0, cnt = 0, mul = 1;

        for (const auto &i : A) {
            cur_sum += i;
            if (cur_sum == part_sum * mul) {
                mul++;
                cnt++;
            }
        }

        return cnt >= 3;
    }
};
