int longestSubarray(int* nums, int numsSize) {
    // 滑动窗口 最多只能有一个0
    int zeroCount = 0;
    int left = 0;
    int right = 0;
    int maxCount = 0;
    while(right < numsSize && left <= right) {
        if(nums[right] == 1) {
            // 右边界为1
            right++;
        } else {
            // 右边界为0
            // 计数
            if(zeroCount <= 0) {
                zeroCount++;
                right++;
            } else {
                // 超出了，滑动窗口
                if(nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
        }
        // 更新
        int count = right - left;
        if(count > maxCount) {
            maxCount = count;
        }
    }
    // 删掉1个元素
    // 0
    if(maxCount == 0) {
        return 0;
    } else {
        return maxCount - 1;
    }
}