/* 给定一个二维数组，其每一行从左到右递增排序，
从上到下也是递增排序。给定一个数，判断这个数
是否在该二维数组中。要求时间复杂度 O(M + N)，
空间复杂度 O(1)。其中 M 为行数，N 为 列数。 */

bool find_num_in_matrix(int target, int **matrix, int M, int N)
{
    int r = 0, c = N - 1;
    while (r < M && c >= 0) {
	if (matrix[r][c] == target)
	    return true;
	else if (matrix[r][c] < target)
	    r++;
	else
	    c--;
    }

    return false;
}
