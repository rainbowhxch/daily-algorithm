struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void s_swap(TreeNode *root)
{
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}

void mirror_tree(TreeNode *root)
{
    if (root == nullptr)
	return;
    s_swap(root);
    mirror_tree(root->left);
    mirror_tree(root->right);
}
