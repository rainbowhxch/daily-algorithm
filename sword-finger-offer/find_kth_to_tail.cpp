/* 链表中倒数第 K 个结点 */

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *find_kth_to_tail(ListNode *head, int k)
{
    if (head == nullptr)
	return head;
    ListNode *first_test_ptr = head;
    while (first_test_ptr != nullptr && k-- > 0)
	first_test_ptr = first_test_ptr->next;

    if (k > 0) return nullptr;

    ListNode *second_test_ptr = head;
    while (first_test_ptr != nullptr) {
	first_test_ptr = first_test_ptr->next;
	second_test_ptr = second_test_ptr->next;
    }

    return second_test_ptr;
}
