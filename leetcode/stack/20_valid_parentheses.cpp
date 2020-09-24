#include <string>
#include <stack>
#include <map>

using std::string;
using std::stack;
using std::map;

class Solution {
public:
    bool isValid(string s) {
		stack<char> sk;
		map<char, char> m;

		m[')'] = '(';
		m['}'] = '{';
		m[']'] = '[';

		for (const auto &c : s) {
			if (m.find(c) != m.end()) {
				if (sk.empty() || m[c] != sk.top())
					return false;

				sk.pop();
			} else {
				sk.push(c);
			}
		}

		return sk.empty();
    }
};
