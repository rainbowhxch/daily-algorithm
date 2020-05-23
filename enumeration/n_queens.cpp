#include <vector>
#include <string>

using std::vector;
using std::string;

vector<vector<string> > res;

bool is_valid(vector<string> board, int row, int col)
{
    for (int i = 0;i < row;++i) {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = 0;i < col;++i) {
        if (board[row][i] == 'Q')
            return false;
    }

    for (int i = row-1, j = col-1;i >= 0 && j >= 0;--i, --j) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void backtrack(vector<string> board, int n)
{
    if (n == board.size()) {
        res.push_back(board);
        return;
    }

    for (int i = 0;i < n;++i) {
        if (!is_valid(board, n, i))
            continue;
        board[n][i] = 'Q';
        backtrack(board, n+1);
        board[n][i] = '.';
    }
}

vector<vector<string> > n_queens(int n)
{
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return res;
}
