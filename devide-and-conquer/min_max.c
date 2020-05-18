#include <stdio.h>

#define SIZE_ARR 4
int a[SIZE_ARR] = {1, 4, 3, 2};
int min, max;

void min_max(int left, int right, int *min, int *max)
{
    if (left == right) {
        *min = *max = a[left];
    } else {
        int mid = (left+right) >> 1;
        int lmin, lmax, rmin, rmax;
        min_max(left, mid, &lmin, &lmax);
        min_max(mid+1, right, &rmin, &rmax);
        *min = lmin < rmin ? lmin : rmin;
        *max = lmax < rmax ? rmax : lmax;
    }
}

int main()
{
    min_max(0, SIZE_ARR-1, &min, &max);
    printf("max=%d, min=%d", max, min);
    return 0;
}
