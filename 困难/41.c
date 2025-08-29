#define MAX 100002
int firstMissingPositive(int* nums, int numsSize) {
    int hash[MAX] = {0};
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] > 0 && nums[i] < MAX) {
            hash[nums[i]]++;
        }
    }
    for(int i = 1;i < MAX;i++) {
        if(hash[i] == 0) {
            return i;
        }
    }
    return 0;
}