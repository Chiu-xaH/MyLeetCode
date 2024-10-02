int pivotIndex(int* nums, int numsSize) {
    for(int i = 0;i < numsSize;i++) {
        int leftTotal = 0,rightTotal = 0;
        for(int j = 0;j < i;j++) {
            leftTotal += nums[j];
        }
        for(int j = i+1;j < numsSize;j++) {
            rightTotal += nums[j];
        }
        if(leftTotal == rightTotal) {
            return i;
        }
    }
    return -1;
}