class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);  
        dp[0] = 0;  //凑出金额 i 所需的最少硬币数

        for(int coin : coins) {
            for(int i = 0;i <= amount;i++) {
                if(coin <= i) {
                    // 凑出i元，可以从凑出 i-coin 再加一枚 coin 来得到
                    dp[i] = min(dp[i-coin]+1,dp[i]);
                }
            }
        }

        if(dp[amount] == INT_MAX) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};