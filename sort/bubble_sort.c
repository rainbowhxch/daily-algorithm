#include <stdio.h>

void print_elem(int a[], int n) {
    for (int i = 0;i < n;++i) {
        printf("%d ", a[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    for (int i = 0;i < n;++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0;i < n-1;++i) {
        for (int j = 0;j < n-i-1;++j) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    print_elem(a, n);
    return 0;
}
