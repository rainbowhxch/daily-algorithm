/* 判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向上下左右移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能
再进入该格子。 */

#include <string>
#include <vector>
using std::string;
using std::vector;

#define SIZE_VISITED 1000000
int row, col;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool backtrack(char **matrix, string s, bool **visited, \
	       int path_len, int r, int c) {
    if (path_len == s.size())
	return true;
    if (r < 0 || r >= row || c < 0 || c >= col || visited[r][c] \
       || matrix[r][c] != s[path_len])
	return false;

    visited[r][c] = true;
    for (int i = 0;i < 4;++i) {
	if (backtrack(matrix, s, visited, path_len+1, r+dir[i][0], c+dir[i][1])) {
	    return true;
	}
    }
    visited[r][c] = false;

    return false;
}

int path_of_matrix(char **matrix, int r, int c, string s)
{
    vector<vector<std::pair<int, int> > > book(26);
    row = r; col = c;
    bool **visited = new bool*[r];
    for (int i = 0;i < r;++i)
	visited[i] = new bool[c];

    for (int i = 0;i < r;++i) {
	for (int j =0;j < c;++j) {
	    book[matrix[i][j] - 'a'].push_back({i, j});
	}
    }

    for (auto i : book[s[0]]) {
	if (backtrack(matrix, s, visited, 0, i.first, i.second))
	    return true;
    }
}
