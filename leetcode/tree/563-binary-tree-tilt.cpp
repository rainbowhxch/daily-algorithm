#include <cmath>
#include <cstdlib>
#include <iostream>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int tilt = 0;

int dfs(TreeNode* root) {
	if (root == nullptr)
		return 0;

	int left_tilt = dfs(root->left);
	int right_tilt = dfs(root->right);

	tilt += abs(left_tilt-right_tilt);

	return left_tilt + right_tilt + root->val;
}

int findTilt(TreeNode* root) {
	dfs(root);

	return tilt;
}
