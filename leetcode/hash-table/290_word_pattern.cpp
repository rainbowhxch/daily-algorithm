#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::istringstream iss(s);
        std::vector<std::string> v((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
        if (pattern.size() != v.size())
            return false;

        unordered_map<char, int> m_c;
        unordered_map<string, int> m_s;
        for (int i = 0;i < v.size();++i) {
            char idx_c = pattern[i];
            string idx_s = v[i];

            if (m_c[idx_c] == 0)
                m_c[idx_c] = i + 1;
            if (m_s[idx_s] == 0)
                m_s[idx_s] = i + 1;
            if (m_c[idx_c] != m_s[idx_s])
                return false;
        }

        return true;
    }
};
