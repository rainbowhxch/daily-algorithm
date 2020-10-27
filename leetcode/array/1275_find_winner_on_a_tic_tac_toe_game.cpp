#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::abs;
using std::string;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int N = 3;
        vector<int> row(N, 0), col(N, 0);
        int diag_1 = 0, diag_2 = 0;
        int cur_player = 1;

        for (const auto &i : moves) {
            row[i[0]] += cur_player;
            col[i[1]] += cur_player;

            if (i[0] == i[1])
                diag_1 += cur_player;
            if (i[0] + i[1] == N-1)
                diag_2 += cur_player;

            if (abs(row[i[0]]) == N || abs(col[i[1]]) == N
                    || abs(diag_1) == N || abs(diag_2) == N)
                return cur_player == 1 ? "A" : "B";

            cur_player *= -1;
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
