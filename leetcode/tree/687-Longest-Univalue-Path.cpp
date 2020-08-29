#include <algorithm>
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = 0;

int dfs(TreeNode *root) {
	if (root == nullptr)
		return 0;

	int l_child_length = dfs(root->left);
	int r_child_length = dfs(root->right);

	int l_cur_length = 0, r_cur_length = 0;
	if (root->left && root->left->val == root->val)
		l_cur_length = l_child_length + 1;
	if (root->right && root->right->val == root->val)
		r_cur_length = r_child_length + 1;

	ans = std::max(ans, l_cur_length+r_cur_length);

	return std::max(l_cur_length, r_cur_length);
}

int work(TreeNode *root) {
	dfs(root);

	return ans;
}
