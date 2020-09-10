#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        string cows_secret = "";
        string cows_guess = "";
        unordered_map<char, int> m;
        int cnt_bulls = 0, cnt_cows = 0;

        for (int i = 0;i < secret.length();++i) {
            if (secret[i] == guess[i]) {
                cnt_bulls++;
            } else {
                cows_secret.push_back(secret[i]);
                cows_guess.push_back(guess[i]);
            }
        }

        for (const auto &c : cows_secret)
            m[c]++;
        for (const auto &c : cows_guess) {
            if (m[c] > 0) {
                cnt_cows++;
                m[c]--;
            }
        }

        return to_string(cnt_bulls) + "A" + to_string(cnt_cows) + "B";
    }
};
