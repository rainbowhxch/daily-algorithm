#include <vector>
#include <cstdint>

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int cnt = 0, m_max = 0, prev_val = INT32_MIN;
std::vector<int> ans;

void inorder(TreeNode *root) {
	if (root == nullptr)
		return;

	inorder(root->left);

	if (prev_val == INT32_MIN)
		prev_val = root->val;

	if (prev_val == root->val) {
		cnt++;
	} else {
		cnt = 1;
		prev_val = root->val;
	}

	if (cnt > m_max) {
		m_max = cnt;
		ans.clear();
		ans.emplace_back(prev_val);
	} else {
		ans.emplace_back(prev_val);
	}

	inorder(root->right);
}

std::vector<int> work(TreeNode *root) {
	inorder(root);

	return ans;
}
