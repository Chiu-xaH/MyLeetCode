/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* list = head;
    struct ListNode* pre = NULL;
    // 处理头节点为目标节点的情况
    if (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        return head;
    }

    while(list) {
        if(list->val == val) {
            pre->next = list->next;
        }
        pre = list;
        list = list->next;
    }
    return head;
}