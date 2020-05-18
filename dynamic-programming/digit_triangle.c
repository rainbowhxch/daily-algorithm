#include <stdio.h>

#define SIZE_TRIANGLE 4
int t[SIZE_TRIANGLE][SIZE_TRIANGLE] = {{1}, {3, 2}, {4, 10, 1}, {4, 3, 2, 20}};

int dp[SIZE_TRIANGLE][SIZE_TRIANGLE];

int max(int a, int b)
{
    if (a < b)  return b;
    else        return a;
}

void digit_triangle()
{
    for (int i = 0;i < SIZE_TRIANGLE;++i) {
      dp[SIZE_TRIANGLE - 1][i] = t[SIZE_TRIANGLE - 1][i];
    }

    for (int i = SIZE_TRIANGLE-2;i >= 0;--i) {
        for (int j = 0;j < SIZE_TRIANGLE;++j) {
            dp[i][j] = t[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
}

int main()
{
    digit_triangle();
    printf("%d", dp[0][0]);
    return 0;
}
