/* 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回 。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。 */

struct TreeNode {
    TreeNode *left, *right, *parent;
    int val;

    TreeNode(int _val)
    {
	val = _val;
	left = right = parent = nullptr;
    }
};

TreeNode *next_node(TreeNode *cur_node)
{
    if (cur_node->right != nullptr) {
	TreeNode *res = cur_node->right;
	while (res->left != nullptr) {
	    res = res->left;
	}
	return res;
    } else {
	while (cur_node->parent != nullptr) {
	    TreeNode *res = cur_node->parent;
	    if (res->left == cur_node) {
	        return res;
	    }
	    cur_node = cur_node->parent;
	}
    }

    return nullptr;
}
