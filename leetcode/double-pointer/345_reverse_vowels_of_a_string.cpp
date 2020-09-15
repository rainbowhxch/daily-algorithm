#include <string>

using std::string;

class Solution {
public:
    string reverseVowels(string s) {
        int i = -1, j = s.size();
        while (i < j) {
            while (i < j && !is_vowels(s[++i]));
            while (i < j && !is_vowels(s[--j]));

            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }

        return s;
    }

private:
    bool is_vowels(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
