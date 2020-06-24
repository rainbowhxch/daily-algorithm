/* 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。假设输入的数组的任意两个数字都互不相同 */

#include <sys/select.h>
#include <type_traits>
#include <vector>
using std::vector;

bool is_postorder_traversal(vector<int> seq, int l, int r)
{
    if (r-l <= 1) return true;

    int rootval = seq[r];
    int first_ridx = l;
    while (first_ridx < r && seq[first_ridx] < rootval)
	first_ridx++;
    for (int i = first_ridx; i < r; i++) {
        if (seq[i] < rootval)
	    return false;
    }

    return is_postorder_traversal(seq, l, first_ridx-1) \
	&& is_postorder_traversal(seq, first_ridx, r);
}

bool is_postorder_traversal(vector<int> seq)
{
    return is_postorder_traversal(seq, 0, seq.size()-1);
}
