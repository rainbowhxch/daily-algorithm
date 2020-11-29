#include <bitset>
#include <string>

using std::bitset;
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        const int N = 1e4+1;
        bitset<N> ba(a), bb(b), bxor, band;
        string res;

        do {
            band = ba & bb << 1;
            bxor = ba ^ bb;
            ba = band;
            bb = bxor;
        }while (band.any());

        res = ba.to_string();
        auto first_one_index = res.find('1');
        return first_one_index == string::npos ? "0" : res.substr(first_one_index);
    }
};
