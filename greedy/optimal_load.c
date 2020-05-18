#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARR 1024
int n, c, w[SIZE_ARR];

int cmptor(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void optimal_load()
{
    int sum = w[0], i = 0;
    qsort(w, n, sizeof(int), cmptor);
    while (sum < c) {
        printf("%d ", w[i]);
        sum += w[i++];
    }
}

int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 0;i < n;++i) {
        scanf("%d", &w[i]);
    }
    optimal_load();
    return 0;
}
