struct TreeNode {
    int val;
    TreeNode *left, *right;
};

bool is_symmentrical_tree(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
	return true;
    if (left == nullptr || right == nullptr)
	return false;
    if (left->val != right->val)
	return false;

    return is_symmentrical_tree(left->left, right->right) \
	|| is_symmentrical_tree(left->right, right->left);
}

bool is_symmentrical_tree(TreeNode *root)
{
    if (root == nullptr)
	return false;

    return is_symmentrical_tree(root->left, root->right);
}
