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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth;
        return dfs(root, depth);
    }
private:
    TreeNode *dfs(TreeNode *root, int &depth) {
        if (root == nullptr) {
            depth = -1;
            return nullptr;
        }

        int left_depth, right_depth;
        TreeNode *left_common = dfs(root->left, left_depth);
        TreeNode *right_common = dfs(root->right, right_depth);

        if (left_depth == right_depth) {
            depth = left_depth + 1;
            return root;
        } else if (left_depth < right_depth) {
            depth = right_depth + 1;
            return right_common;
        } else {
            depth = left_depth + 1;
            return left_common;
        }
    }
};
