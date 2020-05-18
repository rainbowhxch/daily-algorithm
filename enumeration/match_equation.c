#include <stdio.h>

#define SIZE_ARR 10
#define LIMIT 1024
int m, num = 0;
int n[SIZE_ARR] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int match_equation(int x)
{
    int cnt = 0;

    while (x/10 != 0) {
        cnt += n[x%10];
        x = x / 10;
    }
    cnt += n[x];
    return cnt;
}

int main()
{
    scanf("%d", &m);
    for (int i = 0;i < LIMIT;++i) {
        for (int j = 0;j < LIMIT;++j) {
            int k = i + j;
            if (match_equation(i) + match_equation(j)
                + match_equation(k) == m - 4) {
                printf("%d + %d = %d\n", i, j, k);
                num++;
            }
        }
    }
    printf("The number of this equations is: %d", num);

    return 0;
}
