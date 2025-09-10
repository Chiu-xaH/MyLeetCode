struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* list = head;

    while (list) {
        if(list->next && list->next->val == list->val) {
            // 找到终点
            struct ListNode* end = list->next;
            while(end && end->val == list->val) {
                end = end->next;
            }
            // 删除
            while (list != end) {
                struct ListNode* old = list;
                list = list->next;
                free(old);
            }
            prev->next = list;
        } else {
            prev = list;
            list = list->next;
        }
    }
    return dummy.next;
}
