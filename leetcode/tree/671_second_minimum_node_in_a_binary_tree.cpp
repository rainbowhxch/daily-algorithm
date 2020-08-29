#include <cstdint>
#include <stdint.h>

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int m_min;
long ans = INTMAX_MAX;

void dfs(TreeNode *root) {
	if (root != nullptr) {
		if (m_min < root->val && root->val < ans)
			ans = root->val;
	} else if (root->val == m_min) {
		dfs(root->left);
		dfs(root->right);
	}
}

int work(TreeNode *root) {
	m_min = root->val;
	dfs(root);

	return ans < INTMAX_MAX ? (int)ans : -1;
}
