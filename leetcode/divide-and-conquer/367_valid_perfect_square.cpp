class Solution {
public:
    bool isPerfectSquare(int num) {
        using ll = long long;
        int left = 1, right = num/2 + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            ll square = mid * mid;
            if (square == num)
                return true;
            else if (square < num)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
