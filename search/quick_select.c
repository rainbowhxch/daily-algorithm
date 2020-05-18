#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_ARRAY 1024

int n, tar, a[SIZE_ARRAY];

void swap(int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(int l, int r)
{
    int tmp = a[l], i = l;
    while (l != r) {
        while (l < r && a[r] > tmp) r--;
        while (l < r && a[l] < tmp) l++;

        if (l < r) swap(l, r);
    }
    a[r] = a[l];
    a[l] = tmp;
    return r;
}

int quick_select(int l, int r, int k)
{
    if (l == r) return a[l];

    int i = l + rand() % (r-l+1);
    swap(i, l);

    int m = partition(l, r);
    if (k == m) return a[m];
    else if (k < m) return quick_select(l, m-1, k);
    else return quick_select(m+1, r, k-m);
}

int main()
{
    srand(time(NULL));
    scanf("%d", &n);
    scanf("%d", &tar);
    for (int i = 0;i < n;++i) {
        scanf("%d", &a[i]);
    }

    printf("%d", quick_select(0, n-1, tar-1));
    return 0;
}
