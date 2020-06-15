/* 给定一个 double 类型的浮点数 base 和 int 类型的整数 exponent，求 base 的 exponent 次方。 */

double powerful_pow(double base, int exponent)
{
    if (exponent == 0) return 1;

    bool is_nagetive = false;
    if (base < 0) {
	exponent = -exponent;
	is_nagetive = true;
    }

    double res = powerful_pow(base, exponent/2);
    if (exponent & 1)
	res *= base;

    return is_nagetive ? 1/res : res;
}
