
int* transfer(int *nums, int numsSize, int* maxVal) {
    *maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > *maxVal) *maxVal = nums[i];
    }
    
    int* arr = (int*)malloc(sizeof(int) * (*maxVal + 1));
    for (int i = 0; i <= *maxVal; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        arr[nums[i]] += nums[i];
    }

    return arr;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int deleteAndEarn(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int maxVal = 0;
    int* arr = transfer(nums, numsSize, &maxVal);
    int* dp = (int*)malloc(sizeof(int) * (maxVal + 1));

    dp[0] = 0;
    dp[1] = arr[1];

    for (int i = 2; i <= maxVal; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    
    return dp[maxVal];
}
