int climbStairs(int n) {
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
    //上一步结果 上两步结果
    int prev1 = 1, prev2 = 2;
    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return prev2;
}