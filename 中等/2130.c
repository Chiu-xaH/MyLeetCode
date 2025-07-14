/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int Length(struct ListNode* head) {
    int length = 0;
    while(head) {
        length++;
        head = head -> next;
    }
    return length;
}
int pairIndex(int i,int n) {
    return n-1-i;
}
int pairSum(struct ListNode* head) {
    int count = 0;
    int length = Length(head);
    int half = length/2;
    int stack1[half];
    int stack2[half];
    int top1 = -1, top2 = -1;

    struct ListNode* p = head;
    // 前一半进栈1
    // 后一半进栈2
    // 然后同时出栈相加，找出最大值
    for (int i = 0; i < half; i++) {
        stack1[++top1] = p->val;
        p = p->next;
    }
    for (int i = 0; i < half; i++) {
        stack2[++top2] = p->val;
        p = p->next;
    }
    int max = 0;
    for (int i = 0; i < half; i++) {
        int sum = stack1[i] + stack2[pairIndex(i,half)];
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}