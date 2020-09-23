class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 && n == 2)
            return 1;

        int i = 0, j = 1, k = 1;

        for (int m = 3;m <= n;++m) {
            int tmp = k;
            k = i + j + k;
            i = j;
            j = tmp;
        }

        return k;
    }
};
