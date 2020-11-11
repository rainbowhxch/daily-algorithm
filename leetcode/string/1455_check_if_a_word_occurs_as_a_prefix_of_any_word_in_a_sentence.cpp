#include <istream>
#include <sstream>
#include <string>

using std::string;
using std::istringstream;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = 1;
        istringstream ss(sentence);
        string splited;

        while (getline(ss, splited, ' ')) {
            if (isPrefix(searchWord, splited))
                return ans;
            ans++;
        }

        return -1;
    }

private:
    bool isPrefix(string prefix, string word) {
        if (prefix.length() <= word.length()) {
            return word.substr(0, prefix.length()).compare(prefix) == 0;
        }

        return false;
    }
};
