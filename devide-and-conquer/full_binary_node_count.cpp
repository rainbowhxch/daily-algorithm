/* O(logN * logN) */

#include <cmath>
typedef struct _TreeNode {
    _TreeNode *lchild, *rchild;
    int val;
} *TreeNode;

int count_nodes(TreeNode root)
{
    TreeNode l = root, r = root;
    int lhight = 0, rhight = 0;
    while (l != nullptr) {
        l = l->lchild;
        lhight++;
    }
    while (l != nullptr) {
        r = r->rchild;
        rhight++;
    }

    if (lhight == rhight)
        return pow(2, lhight) - 1;

    return 1 + count_nodes(root->lchild) + count_nodes(root->rchild);
}
