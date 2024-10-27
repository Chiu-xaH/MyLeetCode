/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int *newNum = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int index = 0;
    for(int i = 0; i < n; i++) {
        newNum[index++] = nums[i];       // 前半部分
        newNum[index++] = nums[n + i];   // 后半部分
    }
    return newNum;
}