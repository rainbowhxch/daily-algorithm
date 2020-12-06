#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

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
    vector<TreeNode*> allPossibleFBT(int N) {
		if (m.find(N) == m.end()) {
			vector<TreeNode *> ans;
			if (N == 1)
				ans.push_back(new TreeNode(0));
			else if (N%2 == 1) {
				for (int i = 0; i < N; ++i) {
					int j = N - i - 1;
					for (auto left : allPossibleFBT(i)) {
						for (auto right : allPossibleFBT(j)) {
							TreeNode *root = new TreeNode(0, left, right);
							ans.push_back(root);
						}
					}
				}
			}

			m[N] = ans;
		}

		return m[N];
    }
private:
    unordered_map<int, vector<TreeNode *>> m;
};
