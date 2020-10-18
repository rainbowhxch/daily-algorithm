#include <vector>

using std::vector;

class Solution {
public:
    int countLargestGroup(int n) {
        int cnt = 0;
        const int SIZE_ARRAY = 37;
        int cnt_sum[SIZE_ARRAY] = {0};

        for (int i = 1;i <= n;++i) {
            cnt_sum[get_sum_of_number(i)]++;
        }

        int mmax = 0;
        for (int i = 1;i < SIZE_ARRAY;++i) {
            int tmp = cnt_sum[i];
            if (tmp > mmax) {
                mmax = tmp;
                cnt = 1;
            } else if (tmp == mmax) {
                cnt++;
            }
        }

        return cnt;
    }

private:
    int get_sum_of_number(int num) {
        int sum = 0;

        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
};
