struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = new ListNode();
        tmp->next = head;
        head = tmp;

        while (tmp->next != nullptr) {
            if (tmp->next->val == val) {
                ListNode *del = tmp->next;
                tmp->next = tmp->next->next;
                delete del;
            } else {
                tmp = tmp->next;
            }
        }

        return head->next;
    }
};
