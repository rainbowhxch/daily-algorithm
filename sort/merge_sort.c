#include <stdio.h>
#define SIZE_ARRAY 1024

int n;
int a[SIZE_ARRAY], t[SIZE_ARRAY];

void  merge_sort(int l, int r)
{
    if (l >= r) return;

    int m = (l + r) >> 1;
    merge_sort(l, m);
    merge_sort(m+1, r);

    int i = l, j = m+1, k = l;
    while (i <= m && j <= r) {
        if (i <= m && a[i] <= a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }

    while (i <= m)  t[k++] = a[i++];
    while (j <= r)  t[k++] = a[j++];
    for (i = l;i <= r;++i)  a[i] = t[i];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;++i) {
        scanf("%d", &a[i]);
    }

    merge_sort(0, n-1);

    for (int i = 0;i < n;++i) {
        printf("%d ", a[i]);
    }

    return 0;
}
