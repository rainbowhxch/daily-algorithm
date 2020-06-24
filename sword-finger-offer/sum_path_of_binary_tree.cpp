/* 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。 */

#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

vector<vector<int> > res;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void backtrack(TreeNode *root, int target, vector<int> &path)
{
    if (root == nullptr)
	return;

    path.emplace_back(root->val);
    target -= root->val;

    if (target == 0 && root->left == nullptr && root->right == nullptr) {
	res.emplace_back(path);
    } else if (target > 0) {
	backtrack(root->left, target, path);
	backtrack(root->right, target, path);
    }

    path.pop_back();
}

vector<vector<int> > sum_path_of_binary_tree(TreeNode *root, int target)
{
    vector<int> one_test;
    backtrack(root, target, one_test);
    return res;
}
