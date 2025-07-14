/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int midIndex(struct ListNode* head) {
    int length = 0;
    while(head) {
        length++;
        head = head->next;
    }
    return length/2;
}
struct ListNode* deleteMiddle(struct ListNode* head) {
    // 特判只有一个节点的情况
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    int ptr = 0;
    int delPtr = midIndex(head);
    // 记录删除结点的前一个结点
    struct ListNode* list = head;
    // 找到删除结点的前一个结点
    while(ptr + 1 != delPtr) {
        list = list->next;
        ptr++;
    }
    // 删除结点
    struct ListNode* delNode = list->next;
    list->next = delNode->next;
    free(delNode);
    return head;
}