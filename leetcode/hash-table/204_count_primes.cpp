#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;

        int cnt = 0;
        vector<int> is_prime(n, true);

        for (int i = 2;i < std::sqrt(n);++i) {
            for (int j = i * i;j < n;j += i) {
                is_prime[j] = false;
            }
        }

        for (auto i : is_prime) {
            if (i == true)
                cnt++;
        }

        return cnt - 2;
    }
};
