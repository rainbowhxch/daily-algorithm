#include <string>

using std::string;

class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";

        const int base_hex = 16;
        u_int n = num;
        string book_hex = "0123456789abcdef";
        string res = "";
        while (n != 0) {
            int mod = n % base_hex;
            res = book_hex[mod] + res;
            n /= base_hex;
        }

        return res;
    }
};
