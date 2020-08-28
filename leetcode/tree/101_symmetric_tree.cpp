struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool is_symmetric(TreeNode *node1, TreeNode *node2) {
	if (node1 == nullptr && node2 == nullptr)
		return true;
	else if (node1 != nullptr && node2 != nullptr)
		return node1->val == node2->val
			&& is_symmetric(node1->left, node2->right)
			&& is_symmetric(node1->right, node2->left);
	else
		return false;
}

bool work(TreeNode *root) {
	if (root == nullptr)
		return true;

	return is_symmetric(root->left, root->right);
}
