/* 求斐波那契数列的第 n 项 */

int fibonacci(int n)
{
    if (n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_iteration(int n)
{
    if (n <= 1) return n;

    int pre1 = 0, pre2 = 1;
    int res;
    for (int i = 2; i <= n; ++i) {
	res = pre1 + pre2;
	pre1 = pre2;
	pre2 = res;
    }

    return res;
}
