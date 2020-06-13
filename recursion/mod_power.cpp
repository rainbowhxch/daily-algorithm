/* 返回幂运算 a^b 的计算结果与 1337 取模（mod，也就是余数）后的结果 */

#include <vector>
using std::vector;

const int base = 1337;

int power(int n, int e)
{
    if (e == 0) return 1;
    n %= base;

    if ((e & 1) == 0) {
	return (n * power(n, e-1)) % base;
    } else {
	int sub_power = power(n, e/2);
	return (sub_power * sub_power) % base;
    }
}

int mod_power(int n, vector<int> e)
{
    if (e.empty()) return 1;

    int last_factor = e.back();
    e.pop_back();

    return power(mod_power(n, e), 10) * power(n, last_factor);
}
