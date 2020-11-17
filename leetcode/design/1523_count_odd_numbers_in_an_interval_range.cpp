class Solution {
public:
    int countOdds(int low, int high) {
        int dis = high - low;
        if (dis % 2 == 0)
            return dis / 2 + (low % 2 ? 1 : 0);
        else
            return (dis + 1) / 2;
    }
};
