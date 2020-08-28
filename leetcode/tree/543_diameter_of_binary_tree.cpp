#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int diameter = 0;

int dfs(TreeNode* root) {
	if (root == nullptr)
		return 0;

	int l_depth = dfs(root->left);
	int r_depth = dfs(root->right);
	diameter = std::max(diameter, l_depth+r_depth);

	return std::max(l_depth, r_depth) + 1;
}

int work(TreeNode* root) {
	dfs(root);

	return diameter;
}
