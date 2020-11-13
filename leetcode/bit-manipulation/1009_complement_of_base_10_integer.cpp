class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int ans = 0, mul = 1;

        while (N != 0) {
            ans += mul * (N % 2 ? 0 : 1);
            N /= 2;
            mul *= 2;
        }

        return ans;
    }
};
