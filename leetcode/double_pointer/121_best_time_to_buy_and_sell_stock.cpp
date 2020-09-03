#include <vector>
#include <climits>

int work(std::vector<int> &prices) {
	int min_price = INT_MAX, max_profit = 0;

	for (int i = 0;i < prices.size();++i) {
		if (min_price < prices[i])
			min_price = prices[i];
		if (max_profit < prices[i]-min_price)
			max_profit = prices[i] - min_price;
	}

	return max_profit;
}
