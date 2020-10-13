#include <vector>

using std::vector;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        const int N = mat.size();

        for (int i = 0;i < N;i++) {
            sum += mat[i][i] + mat[N-i-1][i];
        }

        if (N % 2 == 1)
            sum -= mat[N/2][N/2];

        return sum;
    }
};
