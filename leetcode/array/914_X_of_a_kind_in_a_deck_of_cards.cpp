#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;

        for (const auto &i : deck) {
            m[i]++;
        }

        int item_cnt = 0;
        for (auto [key, val] : m) {
            if (item_cnt == 0)
                item_cnt = val;
            else
                item_cnt = gcd(item_cnt, val);
        }

        return item_cnt >= 2;
    }

private:
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
};
