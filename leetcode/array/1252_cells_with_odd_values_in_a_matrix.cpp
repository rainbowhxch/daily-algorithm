#include <vector>

using std::vector;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int ans = 0;
        int *row = new int[n];
        int *col = new int[m];

        for (auto i : indices) {
            row[i[0]]++;
            col[i[1]]++;
        }

        int odd_row_cnt = 0;
        for (int i = 0;i < n;++i) {
            if (row[i] % 2 != 0) {
                odd_row_cnt++;
                ans += m;
            }
        }

        int even_row_cnt = n - odd_row_cnt;
        for (int i = 0;i < m;++i) {
            if (col[i] % 2 != 0) {
                ans -= odd_row_cnt;
                ans += even_row_cnt;
            }
        }

        return ans;
    }
};
