class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        var maxLen = 0
        var start = 0
        // 初始化哈希表 值为该字符的下标
        val map = mutableMapOf<Char, Int>()
        // 移动右指针 找到最长的不含重复（哈希表值都为1）串长度，然后记录其长度，开始移动左右指针并更新最大长度
        for (end in s.indices) {
            val ch = s[end]
            if (map.containsKey(ch)) {
                // 遇到重复字符，左指针移动到重复字符后一位
                start = maxOf(map[ch]!!+1,start)
            }
            map[ch] = end
            maxLen = maxOf(maxLen, end - start + 1)
        }
        return maxLen
    }
}