class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0, emptyBottles = 0;

        while (numBottles > 0  || emptyBottles >= numExchange) {
            sum += numBottles;

            emptyBottles += numBottles;
            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
        }

        return sum;
    }
};
