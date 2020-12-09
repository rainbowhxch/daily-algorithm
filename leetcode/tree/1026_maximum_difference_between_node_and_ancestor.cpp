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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val, root->val, ans);
        return ans;
    }
private:
    void dfs(TreeNode *root, int maxValInPath, int minValInPath, int &maxDiff) {
        if (root == nullptr) {
            if (maxValInPath - minValInPath > maxDiff) {
                maxDiff = maxValInPath - minValInPath;
            }
            return;
        }
        if (root->val < minValInPath)
            minValInPath = root->val;
        if (maxValInPath < root->val)
            maxValInPath = root->val;
        dfs(root->left, maxValInPath, minValInPath, maxDiff);
        dfs(root->right, maxValInPath, minValInPath, maxDiff);
    }
};
