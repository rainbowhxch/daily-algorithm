struct ListNode {
    int val;
    ListNode *next;
};

ListNode *merge_two_list(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
	return list2;
    if (list2 == nullptr)
	return list1;

    if (list1->val <= list2->val) {
	list1->next = merge_two_list(list1->next, list2);
	return list1;
    } else {
	list2->next = merge_two_list(list1, list2->next);
	return list2;
    }
}

ListNode *merge_two_list_literation(ListNode *list1, ListNode *list2)
{
    ListNode *new_head;
    ListNode *cur = new_head;

    while (list1 != nullptr && list2 != nullptr) {
	if (list1->val <= list2->val) {
	    cur->next = list1;
	    list1 = list1->next;
	} else {
	    cur->next = list2;
	    list2 = list2->next;
	}
    }

    if (list1 != nullptr) {
        cur->next = list1;
    }
    if (list2 != nullptr) {
        cur->next = list2;
    }

    return new_head->next;
}
