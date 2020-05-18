#include <stdio.h>
#define SIZE_ARR 100+5
int a[SIZE_ARR] = {0}, n;

void quick_sort(int left, int right)
{
    int tmp, i, j;
    if (left >= right-1)
        return;
    tmp = a[left];
    i = left; j = right - 1;
    while (i != j)
    {
        while (a[j] >= tmp && j > i)
            j--;
        while (a[i] <= tmp && i < j)
            i++;
        if (i < j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    a[left] = a[i];
    a[i] = tmp;
    quick_sort(left, i);
    quick_sort(i+1, right);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;++i)
        scanf("%d", &a[i]);
    quick_sort(0, n);
    for (int i = 0;i < n;++i)
        printf("%d ", a[i]);
    return 0;
}
