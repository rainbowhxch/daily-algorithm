#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        dfs(root, s, ans);
        if (root)
            ans.push_back(root);
        return ans;
    }
private:
    void dfs(TreeNode *&root, const unordered_set<int> &s, vector<TreeNode *> &ans) {
        if (root == nullptr)
            return;
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
        if (s.find(root->val) != s.end()) {
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);
            root = nullptr;
        }
    }
};
