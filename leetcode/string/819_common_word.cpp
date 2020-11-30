#include <cctype>
#include <string>
#include <cstring>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_word;
        for (const auto &i : banned)
            banned_word.insert(i);

        string ans;
        int max_cnt = 0;
        unordered_map<string, int> word_cnt;
        string cur_word;
        for (int i = 0; i < paragraph.length(); ++i) {
            char c = paragraph[i];
            if (std::isalpha(c)) {
                cur_word.push_back(std::tolower(c));
                if (i != paragraph.length()-1)
                    continue;
            }

            if (cur_word.length() != 0) {
                if (banned_word.find(cur_word) == banned_word.end()) {
                    word_cnt[cur_word]++;
                    if (word_cnt[cur_word] > max_cnt) {
                        max_cnt = word_cnt[cur_word];
                        ans = cur_word;
                    }
                }
            }
            cur_word.clear();
        }

        return ans;
    }
};
