#include <stdio.h>

#define SIZE_ARR 1024
int n, a[SIZE_ARR], book[SIZE_ARR] = {0};

void dfs(int step)
{
    if (step == n) {
        for (int i = 0;i < n;++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1;i <= n;++i) {
        if (book[i] == 0) {
            a[step] = i;

            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0);

    return 0;
}
