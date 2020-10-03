#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit_cnt = 0;

        while (n != 0) {
            bit_cnt++;
            n &= (n-1);
        }

        return bit_cnt;
    }
};
