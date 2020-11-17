#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;
using std::to_string;

class Solution {
public:
    bool isPathCrossing(string path) {
        int ns_cnt = 0, ew_cnt = 0;
        unordered_set<string> s;
        s.insert("0/0");

        for (const auto &c : path) {
            switch (c) {
                case 'N':
                    ns_cnt++;
                    break;
                case 'S':
                    ns_cnt--;
                    break;
                case 'E':
                    ew_cnt++;
                    break;
                case 'W':
                    ew_cnt--;
                    break;
            }
            string cur_point(to_string(ns_cnt) + "/" + to_string(ew_cnt));
            if (s.count(cur_point))
                return true;
            else
                s.insert(cur_point);
        }

        return false;
    }
};
