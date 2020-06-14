/* 根据二叉树的前序遍历和中序遍历的结果，重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 */

struct TreeNode {
    TreeNode *left, *right;
    int val;

    TreeNode(int _val)
    {
	val = _val;
	left = right = nullptr;
    }
};

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

unordered_map<int, int> index_of_inorder;

TreeNode *rebilud_binary_tree(vector<int> pre, int pre_left, \
			    int pre_right, int in_left)
{
    if (pre_left > pre_right)
	return nullptr;

    TreeNode *root = new TreeNode(pre[pre_left]);
    int in_idx = index_of_inorder[root->val];
    int left_tree_size = in_idx - in_left;

    root->left = rebilud_binary_tree(pre, pre_left+1, \
	    pre_left+left_tree_size, in_left);
    root->right = rebilud_binary_tree(pre, pre_left+left_tree_size+1, \
	    pre_right, in_left+left_tree_size+1);
}

TreeNode *rebilud_binary_tree(vector<int> pre, vector<int> in)
{
    for (int i = 0; i < in.size(); ++i) {
	index_of_inorder[in[i]] = i;
    }
    return rebilud_binary_tree(pre, 0, pre.size()-1, 0);
}
