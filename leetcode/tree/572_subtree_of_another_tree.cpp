struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool equal(TreeNode *x, TreeNode *y) {
	if (x == nullptr && y == nullptr)
		return true;
	if (x == nullptr || y == nullptr)
		return false;

	return x->val == y->val
		&& equal(x->left, y->left)
		&& equal(x->right, y->right);
}

bool work(TreeNode *s, TreeNode *t) {
	if (s == nullptr && t == nullptr)
		return true;
	if (s == nullptr)
		return false;

	return equal(s, t)
		|| work(s->left, t)
		|| work(s->right, t);
}
