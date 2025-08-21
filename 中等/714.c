int max(int a,int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int maxProfit(int* prices, int pricesSize, int fee) {
    int dp1[pricesSize];
    int dp2[pricesSize];
    // dp1表示第i天买入股票，利润
    dp1[0] = -prices[0];
    // dp2表示第i天卖出股票，利润
    dp2[0] = 0;
    for(int i = 1;i < pricesSize;i++) {
        dp2[i] = max(dp2[i-1],dp1[i-1] + prices[i] - fee);
        dp1[i] = max(dp1[i-1],dp2[i-1] - prices[i]);
    }
    return dp2[pricesSize-1];   
}