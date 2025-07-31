int longestOnes(int* nums, int numsSize, int k) {
    int zeroCount = 0;
    int left = 0,right = 0;
    int maxLength = 0;
    // 滑动窗口
    while(right < numsSize) {
        if(nums[right] == 0) {
            zeroCount++;
        }
        if(zeroCount > k) {
            if(nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
        int currentLength = right-left+1;
        if(currentLength > maxLength) {
            maxLength = currentLength;
        }
        right++;
    }
    return maxLength;
}