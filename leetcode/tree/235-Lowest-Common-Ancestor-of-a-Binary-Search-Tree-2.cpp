struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int p_val = p->val;
	int q_val = q->val;

	TreeNode* tmp_root = root;
	while (tmp_root != nullptr) {
		if (p_val > tmp_root->val && q_val > tmp_root->val)
			tmp_root = tmp_root->right;
		else if (p_val < tmp_root->val && q_val < tmp_root->val)
			tmp_root = tmp_root->left;
		else
			return tmp_root;
	}

	return nullptr;
}
