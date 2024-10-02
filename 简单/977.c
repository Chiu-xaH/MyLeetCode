/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
977. 有序数组的平方 简单
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]

*/
 void selectSort(int array[],int size) {
    for(int i = 0;i < size;i++ ) {
        int min = i;
        for(int j = i+1;j < size;j++) {
            if(array[j] < array[min]) {
                min = j;
            }
        }
        if(min != i) {
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
 }
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* newNums = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize;i++) {
        newNums[i] = nums[i] * nums[i];
    }
    selectSort(newNums,numsSize);
    *returnSize = numsSize;
    return newNums;
}