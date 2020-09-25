#include <algorithm>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq(stones.begin(), stones.end());

		while (pq.size() > 1) {
			int x = pq.top();
			pq.pop();
			int y = pq.top();
			pq.pop();

			if (x != y)
				pq.emplace(abs(y-x));
		}

		return pq.empty() ? 0 : pq.top();
    }
};
