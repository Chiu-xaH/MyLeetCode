int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dp[nums1Size+1][nums2Size+1];
    for(int i = 0;i <= nums1Size;i++) {
        for(int j = 0;j <= nums2Size;j++) {
            dp[i][j] = 0;
        }
    }
    
    int result = 0;
    for(int i = nums1Size-1; i >= 0;i--) {
        for(int j = nums2Size-1; j >= 0;j--) {
            if(nums1[i] == nums2[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            } else {
                dp[i][j] = 0;
            }
            if(dp[i][j] > result) {
                result = dp[i][j];
            }
        }
    }
    return result;
}