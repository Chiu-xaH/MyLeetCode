#include <stdio.h>

//  Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
};
 


void TailAdd(struct ListNode** list,int data) {
    struct ListNode* temp = *list;
    while (temp->next) {
        temp = temp->next;
    }
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = data;
        temp->next = newNode;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* newList = (struct ListNode*)malloc(sizeof(struct ListNode));
    newList->next = NULL;
    
    while(list1 && list2) {
        if(list1->val < list2->val) {
            //插1
            TailAdd(&newList,list1->val);
            list1 = list1->next;
        } else {
            //插2
            TailAdd(&newList,list2->val);
            list2 = list2->next;
        }
    }
    while(list1) {
        TailAdd(&newList,list1->val);
        list1 = list1->next;
    }
    while(list2) {
        TailAdd(&newList,list2->val);
        list2 = list2->next;
    }
    return newList->next;
}