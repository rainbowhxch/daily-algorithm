#include <vector>

using std::vector;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i;
        for (i = bits.size()-2;i >= 0 && bits[i] == 1;--i);

        return ((bits.size()-i) % 2) == 0;
    }
};
