#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const auto &i : logs) {
            if (i == "../") {
                if (depth > 0)
                    depth--;
            } else if (i != "./")
                depth++;
        }

        return depth;
    }
};
