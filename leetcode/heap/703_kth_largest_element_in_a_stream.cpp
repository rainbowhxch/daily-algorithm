#include <functional>
#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (auto &i : nums) {
			pq.emplace(i);
			if (pq.size() > k)
				pq.pop();
		}
    }

    int add(int val) {
		pq.emplace(val);
		if (pq.size() > k)
			pq.pop();

		return pq.top();
    }

private:
	priority_queue<int, vector<int>, std::greater<int>> pq;
	int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
