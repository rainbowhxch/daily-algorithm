#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;

        while (pa != pb) {
            pa = (pa != NULL) ? pa->next : headB;
            pb = (pb != NULL) ? pb->next : headA;

            if (pa == headB && pb == headA)
                return NULL;
        }

        return pa;
    }
};
