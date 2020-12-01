#include <vector>

using std::vector;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int l = a > b ? (b > c ? c : b) : (a > c ? c : a); // min
        int h = a < b ? (b < c ? c : b) : (a < c ? c : a); // max
        int m =  a != l && a != h ? a : (b != l && b != h ? b : c); // mid

        if((h-l) != 2){
            int startDifference = m-l-1;
            int endDifference = h-m-1;
            return {startDifference <= 1 || endDifference <= 1 ? 1 : 2, h-l-2};
        }

        return {0, 0};
    }
};
