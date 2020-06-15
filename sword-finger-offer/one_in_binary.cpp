/* 输入一个整数，输出该数二进制表示中 1 的个数。 */

int one_in_binary_1(int n)
{
    int cnt = 0;
    while (n != 0) {
        cnt++;
	n &= (n-1);
    }

    return cnt;
}

int one_in_binary_2(int n)
{
    int cnt = 0;
    while (n != 0) {
	if (n & 1)
	    cnt++;
	n >>= 1;
    }

    return cnt;
}
