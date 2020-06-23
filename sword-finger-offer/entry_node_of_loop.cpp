struct ListNode {
    int val;
    ListNode *next;
};

ListNode *entry_node_of_loop(ListNode *head)
{
    ListNode *slow_ptr = head, *fast_ptr = head;

    do {
	slow_ptr = slow_ptr->next;
	fast_ptr = fast_ptr->next->next;
    } while (slow_ptr != fast_ptr);

    fast_ptr = head;
    while (slow_ptr != fast_ptr) {
	slow_ptr = slow_ptr->next;
	fast_ptr = fast_ptr->next;
    }

    return fast_ptr;
}
