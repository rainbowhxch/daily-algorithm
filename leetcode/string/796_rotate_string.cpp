#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    bool rotateString(string A, string B) {
        int N = A.length();
        if (N != B.length()) return false;
        if (N == 0) return true;

        vector<int> shift(N+1, 1);
        int left = -1;
        for (int right = 0; right < N; ++right) {
            while (left >= 0 && (B[left] != B[right]))
                left -= shift[left];
            shift[right+1] = right - left++;
        }

        int match_len = 0;
        for (const auto &c : A+A) {
            while (match_len >= 0 && B[match_len] != c)
                match_len -= shift[match_len];
            if (++match_len == N)
                return true;
        }

        return false;
    }
};
