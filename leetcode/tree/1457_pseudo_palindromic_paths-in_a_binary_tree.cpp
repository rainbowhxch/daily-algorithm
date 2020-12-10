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
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt, 0);
        return cnt;
    }
private:
    void dfs(TreeNode *root, int &count, int path) {
        if (root == nullptr)
            return;

        path = path ^ (1 << root->val);
        if (root->left == nullptr && root->right == nullptr && (path&(path-1)) == 0)
            ++count;

        dfs(root->left, count, path);
        dfs(root->right, count, path);
    }
};
