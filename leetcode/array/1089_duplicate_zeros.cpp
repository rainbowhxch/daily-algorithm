#include <vector>

using std::vector;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int duplicate_cnt = 0;
        int n = arr.size() - 1;

        for (int i = 0; i <= n-duplicate_cnt; ++i) {
            if (arr[i] == 0) {
                if (i == n-duplicate_cnt) {
                    arr[n] = 0;
                    n--;
                    break;
                }
                duplicate_cnt++;
            }
        }

        for (int i = n-duplicate_cnt; i >= 0;--i) {
            if (arr[i] == 0) {
                arr[i+duplicate_cnt] = 0;
                duplicate_cnt--;
                arr[i+duplicate_cnt] = 0;
            } else {
                arr[i+duplicate_cnt] = arr[i];
            }
        }
    }
};
