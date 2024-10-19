

struct ListNode* reverseList(struct ListNode* head) {
     // 如果链表为空或只有一个节点，不需要反转
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *pre = NULL;  // 保存前一个节点的指针
    struct ListNode *curr = head;  // 当前节点指针
    struct ListNode *nexts = NULL;  // 保存下一个节点的指针

    // 迭代地反转链表
    while (curr != NULL) {
        nexts = curr->next;  // 暂存下一个节点
        curr->next = pre;  // 当前节点指向前一个节点
        pre = curr;  // 前一个节点更新为当前节点
        curr = nexts;  // 移动到下一个节点
    }

    // 最终 `pre` 是新的头节点
    return pre;
}