/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findMinAndDelete(int *nums,int numsSize) {
    int min = 101;
    int index = -1;
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] < min && nums[i] >= 0) {
            min = nums[i];
            index = i;
        }
    }
    //删除
    if(index != -1)
    nums[index] = -1;
    if(min != 101)
    return min;
    else 
    return -1;
}


int* numberGame(int* nums, int numsSize, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int) * numsSize);
    *returnSize  = 0;
    while((*returnSize) != numsSize) {
        int alice = findMinAndDelete(nums,numsSize);
        int bob = findMinAndDelete(nums,numsSize);
        if(bob != -1)
        arr[(*returnSize)++] = bob;
        if(alice != -1)
        arr[(*returnSize)++] = alice;
    }
    return arr;
}