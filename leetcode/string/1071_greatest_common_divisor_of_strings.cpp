#include <string>

using std::string;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 == str2)
            return str1;
        if (str1.size() < str2.size())
            swap(str1, str2);
        return str1.substr(0, str2.size()) != str2 ? "" : gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
