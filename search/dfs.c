#include <stdio.h>

#define GEO 51
int n, m, x, y, p, q, min = 1e6;
int d[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int a[GEO][GEO], book[GEO][GEO];

void dfs(int x, int y, int step)
{
    int tx, ty;
    if (x == p && y == q) {
        if (step < min) {
            min = step;
        }
        return;
    }

    for (int i = 0;i < 4;++i) {
        tx = x + d[i][0];
        ty = y + d[i][1];

        if (tx < 1 || tx > n || ty < 1 || ty > n)
            continue;

        if ( a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty, step+1);
            book[tx][ty] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= m;++j) {
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d %d %d %d", &x, &y, &p, &q);
    book[x][y] = 1;
    dfs(x, y, 0);
    printf("%d", min);
}
