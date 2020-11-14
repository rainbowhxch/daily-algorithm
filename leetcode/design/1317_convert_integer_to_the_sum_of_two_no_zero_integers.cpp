#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1;i < n;++i) {
            if (is_no_zero_integer(i) && is_no_zero_integer(n-i))
                return {i, n-i};
        }

        return {-1, -1};
    }

private:
    bool is_no_zero_integer(int num) {
        while (num != 0) {
            if (num % 10 == 0)
                return false;
            num /= 10;
        }

        return true;
    }
};
