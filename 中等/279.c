int min(int a,int b) {
    if(a > b) {
        return b;
    } else {
        return a;
    }
}

int numSquares(int n) {
    int dp[n+1];
    for(int i = 0;i <= n;i++) {
        dp[i] = i;
        for(int j = 1;i - j*j >= 0;j++) {
            dp[i] = min(dp[i-j*j] + 1,dp[i]);
        }
    }
    return dp[n];
}