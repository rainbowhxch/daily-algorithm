struct TreeNode {
    int val;
    TreeNode *left, *right;
};

bool is_subtree_with_root(TreeNode *root, TreeNode *sub_tree)
{
    if (sub_tree == nullptr)
	return true;
    if (root == nullptr)
	return false;
    if (root->val != sub_tree->val)
	return false;

    return is_subtree_with_root(root->left, sub_tree->left) \
	&& is_subtree_with_root(root->right, sub_tree->right);
}

bool has_subtree(TreeNode *ori_tree, TreeNode *sub_tree)
{
    if (ori_tree == nullptr || sub_tree == nullptr)
	return false;

    return is_subtree_with_root(ori_tree, sub_tree) \
	|| has_subtree(ori_tree->left, sub_tree) \
	|| has_subtree(ori_tree->right, sub_tree);
}
