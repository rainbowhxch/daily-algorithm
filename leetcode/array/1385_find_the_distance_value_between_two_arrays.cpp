#include <vector>

using std::vector;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        const int tmp_size = 1105;
        int cnt = 0;
        vector<int> book(tmp_size*2, 0);

        for (const auto &i : arr2) {
            book[i+tmp_size]++;
        }

        for (const auto &i : arr1) {
            int tmp = 0;
            for (int k = -d;k <= d;++k) {
                tmp += book[i+tmp_size+k];
            }

            if (tmp == 0)
                cnt++;
        }

        return cnt;
    }
};
