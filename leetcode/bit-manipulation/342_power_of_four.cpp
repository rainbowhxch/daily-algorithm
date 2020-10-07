class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0 || (num & (num-1)))
            return false;

        while (num != 0) {
            if (num & 0x2)
                return false;
            num >>= 2;
        }

        return true;
    }
};
