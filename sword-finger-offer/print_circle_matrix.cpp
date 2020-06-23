/* 顺时针打印矩阵 */

#include <vector>
using std::vector;

vector<int> print_loop_matrix(vector<vector<int> > matrix)
{
    vector<int> res;
    int r1 = 0, r2 = matrix.size() - 1;
    int c1 = 0, c2 = matrix[0].size() - 1;
    while (r1 <= r2 && c1 <= c2) {
        for (int i = c1;i <= c2;++i)
	    res.emplace_back(matrix[r1][i]);
        for (int i = r1-1;i <= r2;++i)
	    res.emplace_back(matrix[i][c2]);
	if (r1 < r2) {
	    for (int i = c2-1;i >= c1;--i)
		res.emplace_back(matrix[r1][i]);
	}
	if (c1 < c2) {
	    for (int i = r2-1;i > r1;--i)
		res.emplace_back(matrix[c1][i]);
	}
	r1++; r2--; c1++; c2--;
    }

    return res;
}
