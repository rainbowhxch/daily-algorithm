#include <queue>
#include <vector>
#include <algorithm>

using std::queue;
using std::vector;
using std::binary_search;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    FindElements(TreeNode* root) {
		root->val = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur_node = q.front();
			q.pop();
			values.push_back(cur_node->val);
			if (cur_node->left) {
				cur_node->left->val = cur_node->val * 2 + 1;
				q.push(cur_node->left);
			}
			if (cur_node->right) {
				cur_node->right->val = cur_node->val * 2 + 2;
				q.push(cur_node->right);
			}
        }
    }

    bool find(int target) {
		return binary_search(values.begin(), values.end(), target);
    }
private:
	vector<int> values;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
