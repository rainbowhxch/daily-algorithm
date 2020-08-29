struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool work(TreeNode *root, int sum) {
	if (root == nullptr)
		return false;
	if (root->left == nullptr && root->right == nullptr && root->val == sum)
		return true;

	return work(root->left, sum - root->val)
		|| work(root->right, sum - root->val);
}
