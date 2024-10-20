int max(int a,int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0; // 没有房屋
    if (numsSize == 1) return nums[0]; // 只有一间房屋
    int dp[numsSize+1];
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2;i <= numsSize;i++) {
        dp[i] = max(dp[i-1],nums[i-1]+dp[i-2]);
    }
    return dp[numsSize];
}
//思路：第一步要不偷第一家，要么第二家，然后错开偷