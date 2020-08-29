#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int work(TreeNode *root) {
	if (root == nullptr)
		return 0;

	int l_min_depth = work(root->left) + 1;
	int r_min_depth = work(root->right) + 1;

	if (!root->left || !root->right)
		return root->left == nullptr ? r_min_depth : l_min_depth;

	return std::min(l_min_depth, r_min_depth);
}
