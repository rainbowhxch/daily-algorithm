struct ListNode {
    int val;
    ListNode *next;
};

ListNode *reverse_list(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
	return head;

    ListNode *next_node = head->next;
    head->next = nullptr;
    ListNode *new_head = reverse_list(head->next);
    next_node->next = head;

    return new_head;
}

ListNode *reverse_list_literation(ListNode *head)
{
    ListNode *new_list;
    while (head != nullptr) {
	ListNode *next_node = head->next;
	head->next = new_list->next;
	new_list->next = head;
	head = next_node;
    }
}
