class Solution {
    fun longestValidParentheses(s: String): Int {
        if(s.length in 0..1) {
            return 0
        }
        val dp = IntArray(s.length)
        var maxLen = 0
        dp[0] = 0
        // 动态规划
        for(i in 1 until s.length) {
            if(s[i] == '(') {
                dp[i] = 0
            } else {
                if(s[i-1] == '(') {
                    // ()
                    dp[i] = (if(i >= 2) dp[i - 2] else 0) + 2
                } else {
                    // ))
                    val preIndex = i - dp[i - 1] - 1
                    if (preIndex >= 0 && s[preIndex] == '(') {
                        dp[i] = dp[i - 1] + 2 + if (preIndex - 1 >= 0) dp[preIndex - 1] else 0
                    }
                }
            }
            maxLen = maxOf(maxLen,dp[i])
        }
        return maxLen
    }
}