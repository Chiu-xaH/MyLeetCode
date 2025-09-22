class Solution {
    fun partition(s: String): List<List<String>> {
        val res = mutableListOf<List<String>>()
        val path = mutableListOf<String>()

        // 动态规划
        val dp = Array(s.length) { BooleanArray(s.length) }
        /*
        o o o
        o @ o
        Q o o

        @ = Q
        所以i应该倒序推(UP) j应该正序推(RIGHT)
         */
        for (i in s.length - 1 downTo 0) {
            for (j in i until s.length) {
                if (s[i] == s[j]) {
                    // 一个字符或两个字符相同
                    if (j - i <= 1) {
                        dp[i][j] = true
                    } else {
                        dp[i][j] = dp[i + 1][j - 1]
                    }
                }
            }
        }

        // 回溯
        fun dfs(start: Int) {
            // 收集答案
            if (start == s.length) {
                res.add(path.toList()) 
                return
            }
            for (end in start until s.length) {
                if(dp[start][end]) {
                    // 是回文
                    path.add(s.substring(start,end+1))
                    dfs(end+1)
                    // 回溯
                    path.removeLast()
                }
            }
        }

        dfs(0)
        return res
    }
}
