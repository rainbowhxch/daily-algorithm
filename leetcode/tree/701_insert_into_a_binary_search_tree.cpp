struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode *tmp = root, *pre;
        while (tmp) {
            pre = tmp;
            if (tmp->val < val)
                tmp = tmp->right;
            else
                tmp = tmp->left;
        }

        if (pre->val < val)
            pre->right = new TreeNode(val);
        else
            pre->left = new TreeNode(val);

        return root;
    }
};
