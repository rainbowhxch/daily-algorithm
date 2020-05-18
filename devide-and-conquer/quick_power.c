#include <stdio.h>
#include <stdlib.h>

int quick_power(int n, int p)
{
    if (p == 0) return 1;
    if (p & 1) {
        return quick_power(n, p-1) * n;
    } else {
        int t = quick_power(n, p>>1);
        return t*t;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <number> <power>", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int p = atoi(argv[2]);
    printf("%d", quick_power(n, p));
    return 0;
}
