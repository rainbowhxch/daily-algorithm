#include <cstdlib>
#include <vector>
using std::vector;

int dir[4][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };
int threshold, cnt = 0;
int row, col;
int **digit_sum;

void init_sum()
{
    int *sum_one = new int[std::max(row, col)];
    for (int i = 0;i < std::max(row, col);++i) {
	int tmp = i;
	while (tmp > 0) {
	    sum_one[i] += tmp % 10;
	    tmp /= 10;
	}
    }

    digit_sum = new int*[row];
    for (int i = 0;i < row;++i)
	digit_sum[i] = new int[col];

    for (int i = 0;i < row;++i) {
	for (int j = 0;j < col;++j) {
	    digit_sum[i][j] = sum_one[i] + sum_one[j];
	}
    }
}

void dfs(int r, int c, bool **visited)
{
    if (r < 0 || r >= row || c < 0 || c >= col || visited[r][c])
	return;

    visited[r][c] = true;

    if (digit_sum[r][c] > threshold)
	return;

    cnt++;
    for (int i = 0;i < 4;++i)
	dfs(r+dir[i][0], c+dir[i][1], visited);
}

int range_of_robot(int t, int r, int c)
{
    threshold = t;
    row = r; col = c;
    init_sum();
    bool **visited = new bool*[r];
    for (int i = 0;i < r;++i)
	visited[i] = new bool[c];

    dfs(0, 0, visited);

    return cnt;
}
