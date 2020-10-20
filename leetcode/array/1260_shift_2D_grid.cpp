#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int> > new_grid(m, vector<int>(n, 0));

        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                int tmp = j + k;
                int new_j = tmp % n;
                int new_i = (tmp / n + i) % m;
                new_grid[new_i][new_j] = grid[i][j];
            }
        }

        return new_grid;
    }
};
