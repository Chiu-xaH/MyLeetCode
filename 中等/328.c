/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* LinkList;

LinkList oddEvenList(LinkList head) {
    if (!head || !head->next) return head;

    LinkList odd = head;               // 奇数位置链表当前节点
    LinkList even = head->next;        // 偶数位置链表当前节点
    LinkList evenHead = even;          // 偶数链表头节点

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;        // 奇数节点指向下一个奇数节点
        odd = odd->next;               // 奇数指针前进

        even->next = odd->next;        // 偶数节点指向下一个偶数节点
        even = even->next;             // 偶数指针前进
    }

    odd->next = evenHead;              // 将奇数链表尾接上偶数链表头
    return head;
}