/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    int count = 0;
    //if(head == NULL) return true;
    
    while(head) {
        head = head->next;
        count++;
        if(count > 10000) {
            return true;
        }
    }
    return false;
}