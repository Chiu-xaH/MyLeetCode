int max(int a,int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}
int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize];
    int maxLen = 1;
    for(int i = 0;i < numsSize;i++) {
        dp[i] = 1;
    }
    for(int i = 1;i < numsSize;i++) {
        for(int j = 0;j < i;j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen,dp[i]);
    }
    return maxLen;
}