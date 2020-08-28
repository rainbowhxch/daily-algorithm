struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr)
		return nullptr;

	if (p->val > root->val && q->val > root->val)
		return lowestCommonAncestor(root->right, p, q);
	else if (p->val < root->val && q->val < root->val)
		return lowestCommonAncestor(root->left, p, q);
	else
		return root;
}
