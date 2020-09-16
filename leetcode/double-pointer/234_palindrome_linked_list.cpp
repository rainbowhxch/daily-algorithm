struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        slow = reverse(slow);

        while (slow != nullptr) {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

private:
    ListNode *reverse(ListNode *head) {
        ListNode *prev_node = nullptr;
        while (head != nullptr) {
            ListNode *next_node = head->next;
            head->next = prev_node;
            prev_node = head;
            head = next_node;
        }

        return prev_node;
    }
};
