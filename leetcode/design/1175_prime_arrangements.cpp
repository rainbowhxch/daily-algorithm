#include <vector>
#include <algorithm>

using std::vector;
using std::distance;
using std::upper_bound;

class Solution {
public:
  int numPrimeArrangements(int n) {
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
      long ans = 1;
      int k = distance(prime.begin(), upper_bound(prime.begin(), prime.end(), n));

      for (int i = 1; i <= k; ++i) {
        ans = ans * i % MOD;
      }

      for (int i = 1; i<= n-k; ++i) {
        ans = ans * i % MOD;
      }

      return ans;
  }
private:
  const long MOD = 1e9 + 7;
};
