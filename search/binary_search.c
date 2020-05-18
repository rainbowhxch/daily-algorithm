#include <stdio.h>

#define SIZE_ARRAY 1024
int a[SIZE_ARRAY] = {0};
int n = 0;

int binary_search(int k)
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left+right) / 2;
        int mid_val = a[mid];

        if (mid_val == k) {
            return mid;
        } else if (mid_val < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;++i) {
        scanf("%d", &a[i]);
    }
    int k;
    scanf("%d", &k);
    printf("The number locate on pos %d.", binary_search(k));
}
