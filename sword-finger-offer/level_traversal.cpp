/* 从上往下打印出二叉树的每个节点，同层节点从左至右打印。 */

#include <algorithm>
#include <queue>
#include <vector>
using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

vector<int> level_traversal(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<int> res;
    q.push(root);
    while (!q.empty()) {
        int cnt = q.size();

	while (cnt--) {
	    TreeNode *tmp = q.front();
	    q.pop();

	    if (tmp == nullptr)
		continue;

	    res.emplace_back(tmp->val);
	    q.push(tmp->left);
	    q.push(tmp->right);
	}
    }

    return res;
}
