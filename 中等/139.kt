class Solution {
    fun wordBreak(s: String, wordDict: List<String>): Boolean {
        val dp = BooleanArray(s.length+1) { false }
        dp[0] = true
        for(i in 1..s.length) {
            wordDict.forEach { word ->
                val length = word.length
                val left = i - length
                if(left >= 0 && dp[left] && s.substring(left,i) == word) {
                    dp[i] = true
                }
            }
        }
        return dp[s.length]
    }
}