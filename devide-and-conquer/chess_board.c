#include <stdio.h>
#include <math.h>

#define SIZE_BOARD 1000+5
int board[SIZE_BOARD][SIZE_BOARD];
int cnt = 1;

void chess_board(int r1, int c1, int r2, int c2, int size)
{
    if (1 == size)  return;
    int half_size = size / 2;
    if (r2 < r1 + half_size && c2 < c1 + half_size) {
        chess_board(r1, c1, r2, c2, half_size);
    } else {
        board[r1+half_size-1][c1+half_size-1] = cnt;
        chess_board(r1, c1, r1+half_size-1, c1+half_size-1, half_size);
    }

    if (r2 < r1 + half_size && c2 >= c1 + half_size) {
        chess_board(r1, c1+half_size, r2, c2, half_size);
    } else {
        board[r1+half_size-1][c1+half_size] = cnt;
        chess_board(r1, c1+half_size, r1+half_size-1, c1+half_size, half_size);
    }

    if (r2 >= r1 + half_size && c2 < c1 + half_size) {
        chess_board(r1+half_size, c1, r2, c2, half_size);
    } else {
        board[r1+half_size][c1+half_size-1] = cnt;
        chess_board(r1+half_size, c1, r1+half_size, c1+half_size-1, half_size);
    }

    if (r2 >= r1 + half_size && c2 >= c1 + half_size) {
        chess_board(r1+half_size, c1+half_size, r2, c2, half_size);
    } else {
        board[r1+half_size][c1+half_size] = cnt;
        chess_board(r1+half_size, c1+half_size, r1+half_size, c1+half_size, half_size);
    }
}

int main()
{
    int k;
    int i, j;
    scanf("%d", &k);
    int t1 = (int)pow(2, k);
    int t2 = t1 / 2;
    board[t2][t2] = 0;
    chess_board(0, 0, t2, t2, t1);
    for (i = 0;i < t1;++i) {
        for (j = 0;j < t1;++j) {
            printf("%-4d", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
