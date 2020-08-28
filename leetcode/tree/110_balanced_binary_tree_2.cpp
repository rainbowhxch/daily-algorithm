#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int get_height(TreeNode *root, int cur = 1) {
	return root ? std::max(get_height(root->left, cur+1), get_height(root->right, cur+1)) + 1
				: cur;
}

bool work(TreeNode *root) {
	return root ? std::abs(get_height(root->left) - get_height(root->right)) < 2
				&& work(root->left) && work(root->right) : true;
}
