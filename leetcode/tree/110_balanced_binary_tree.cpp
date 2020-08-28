#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int get_height(TreeNode *root) {
	if (root == nullptr)
		return 0;

	int left = get_height(root->left);
	int right = get_height(root->right);
	if (left == -1 || right == -1 || std::abs(left-right) > 1)
		return -1;

	return std::max(left, right) + 1;
}

bool work(TreeNode *root) {
	if (root == nullptr)
		return true;

	return get_height(root) != -1;
}
