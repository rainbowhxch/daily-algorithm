#include <stdio.h>

#define SIZE_ARR 1024
int n, a[SIZE_ARR];

void insert_sort()
{
    for (int i = 1;i < n;++i) {
        int tmp = a[i];
        for (int j = i-1;j >= 0 && a[j]>tmp;--j) {
            a[i+1] = a[i];
        }
        a[i+1] = tmp;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;++i) {
        scanf("%d", &a[i]);
    }

    insert_sort();

    for (int i = 0;i < n;++i) {
        printf("%d", a[i]);
    }

    return 0;
}
