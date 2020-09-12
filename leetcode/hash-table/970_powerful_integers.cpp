#include <vector>
#include <set>
#include <cmath>

using std::vector;
using std::set;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> power_x, power_y;
        const int bound_cnt = 20;

        for (int i = 0; i < bound_cnt && pow(x, i) < bound; i++) {
            power_x.push_back((int)(pow(x, i)));
        }
        for (int i = 0; i < bound_cnt && pow(y, i) < bound; i++) {
            power_y.push_back((int)(pow(y, i)));
        }

        set<int> s;
        for (int i = 0;i < power_x.size();++i) {
            for (int j = 0;j < power_y.size();++j) {
                int sum = power_x[i] + power_y[j];
                if (sum <= bound)
                    s.insert(sum);
            }
        }

        vector<int> v(s.begin(), s.end());
        return v;
    }
};
