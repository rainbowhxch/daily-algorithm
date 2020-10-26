#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
using std::accumulate;
using std::min;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            int tmp = start;
            start = destination;
            destination = tmp;
        }

        int total_sum = accumulate(distance.begin(), distance.end(), 0);
        int bus_sum = accumulate(distance.begin()+start, distance.begin()+destination, 0);

        return min(bus_sum, total_sum-bus_sum);
    }
};
