int pivotIndex(int* nums, int numsSize) {
    int total = 0;
    for(int i = 0;i < numsSize;i++) {
        total += nums[i];
    }
    for(int i = 0;i < numsSize;i++) {
        int leftTotal = 0;
        for(int j = 0;j < i;j++) {
            leftTotal += nums[j];
        }
        int rightTotal = total - leftTotal - nums[i];
        if(leftTotal == rightTotal) {
            return i;
        }
    }
    return -1;
}