#include <vector>

using std::vector;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (auto &i : arr) {
            cnt = i % 2 == 1 ? cnt+1 : 0;

            if (cnt == 3)
                return true;
        }

        return false;
    }
};
