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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
private:
    int dfs(TreeNode *root, int &move_cnt) {
        if (root == nullptr)
            return 0;

        int left_excess = dfs(root->left, move_cnt);
        int right_excess = dfs(root->right, move_cnt);
        move_cnt += abs(left_excess) + abs(right_excess);

        return root->val + left_excess + right_excess - 1;
    }
};
