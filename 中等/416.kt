class Solution {
    fun canPartition(nums: IntArray): Boolean {
        if (nums.size < 2) {
            return false
        }

        val sumValue = nums.sum()
        if (sumValue % 2 == 1) {
            return false
        }
        
        val target = sumValue / 2
        val maxValue = nums.max()
        if (maxValue > target) {
            return false
        }

        // 动态规划
        // dp[i][j] 表示在前 i 个数里，是否可以选出和为 j
        val dp = Array(nums.size + 1) { BooleanArray(target + 1) }
        // 初始化：和为 0 一定能选出来
        for (i in 0..nums.size) {
            dp[i][0] = true
        }

        for (i in 1..nums.size) {
            val curNum = nums[i - 1]
            for (j in 1..target) {
                dp[i][j] = dp[i - 1][j]
                if (j >= curNum) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - curNum] 
                }
            }
        }

        return dp[nums.size][target]
    }
}