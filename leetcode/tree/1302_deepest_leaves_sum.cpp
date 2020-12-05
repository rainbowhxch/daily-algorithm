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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maxHeight = 0;

        dfs(root, 0, maxHeight, sum);

        return sum;
    }

private:
    void dfs(TreeNode* root, int height, int &maxHeight, int &sum) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            if (height > maxHeight) {
                maxHeight = height;
                sum = root->val;
            } else if (height == maxHeight) {
                sum += root->val;
            }
        }
        dfs(root->left, height+1, maxHeight, sum);
        dfs(root->right, height+1, maxHeight, sum);
    }
};
