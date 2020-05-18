#include <stdio.h>

#define SIZE_ARR 51
struct note
{
    int x;
    int y;
    int step;
};
struct note que[SIZE_ARR * SIZE_ARR];
int head, tail, n, m, x, y, p, q;
int a[SIZE_ARR][SIZE_ARR] = {0};
int book[SIZE_ARR][SIZE_ARR] = {0};
int d[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= m;++j) {
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d %d %d %d", &x, &y, &p, &q);
    head = tail = 1;
    que[tail].x = x; que[tail].y = y; que[tail].step = 0;
    tail++; book[x][y] = 1;
    while (head < tail) {
        for (int i = 0;i < 4;++i) {
            int tx = que[head].x + d[i][0];
            int ty = que[head].y + d[i][1];
            if (tx < 1 || tx > n || ty < 1 || ty > n)
                continue;

            if (a[tx][ty] == 0 && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].step = que[head].step+1;
                tail++;
            }

            if (tx == p && ty == q)
                goto _FIN;
        }
    }

_FIN:
    printf("%d", que[tail-1].step);

    return 0;
}
