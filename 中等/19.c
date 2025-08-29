/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* list = head;
    int count = 0;
    while(list) {
        count++;
        list = list->next;
    }

    int delIndex = count - n + 1;
    if(delIndex == 1) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct ListNode* prev = head;
    list = head->next;
    count = 2;
    while(list && count < delIndex) {
        count++;
        prev = list;
        list = list->next;
    }
    // 删除
    prev->next = list->next;
    free(list);
    return head;
}