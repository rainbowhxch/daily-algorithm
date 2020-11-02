#include <vector>

using std::vector;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int N = A.size() - 1;
        A[N] += K;

        for (int i = N;i > 0;--i) {
            if (A[i] < 10)
                break;
            A[i-1] += A[i] / 10;
            A[i] %= 10;
        }
        while (A[0] >= 10) {
            A.insert(A.begin(), A[0] / 10);
            A[1] %= 10;
        }

        return A;
    }
};
