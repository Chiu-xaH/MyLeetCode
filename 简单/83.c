/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
   
    struct ListNode* list = head;
    while (list->next != NULL) {  // 确保list->next不是NULL
        if (list->next->val == list->val) {
            struct ListNode* old = list->next;
            list->next = old->next;
            free(old);
        } else {
            list = list->next;  // 只有当不需要删除时才移动指针
        }
    }
    return head;
}