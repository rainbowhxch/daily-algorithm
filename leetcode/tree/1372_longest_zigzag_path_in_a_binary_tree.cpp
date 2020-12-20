#include <algorithm>

using std::max;

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
    int longestZigZag(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ans = 0;
        dfs(root->left, true, 1, ans);
        dfs(root->right, false, 1, ans);
        return ans;
    }
private:
    void
    dfs(TreeNode *root, bool isLeft, int curPathLength, int &maxPathLength) {
        if (root == nullptr)
            return;
        maxPathLength = max(curPathLength, maxPathLength);
        dfs(root->left, true, isLeft ? 1 : curPathLength+1, maxPathLength);
        dfs(root->right, false, !isLeft ? 1 : curPathLength+1, maxPathLength);
    }
};
