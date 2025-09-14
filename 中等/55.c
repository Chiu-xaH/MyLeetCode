int max(int i, int j) {
    if(i > j) {
        return i;
    } else {
        return j;
    }
}

bool canJump(int* nums, int numsSize) {
    int k = 0;
    for(int i = 0;i < numsSize;i++) {
        if(i > k) {
            return false;
        }
        k = max(i+nums[i],k);
    }
    return true;
}