class Solution {
public:
    int xorOperation(int n, int start) {
		int i = start;

		while (--n) {
			start += 2;
			i ^= start;
		}

		return i;
    }
};
