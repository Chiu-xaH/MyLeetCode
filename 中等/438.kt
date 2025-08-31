class Solution {
    fun findAnagrams(s: String, p: String): List<Int> {
        if (s.length < p.length) return emptyList()
        
        val result = mutableListOf<Int>()
        val pCount = IntArray(26)
        for (ch in p) {
            pCount[ch - 'a']++
        }
        val sCount = IntArray(26)
        var start = 0
        // 右侧下标用 start+p.length-1
        for(i in start..start+p.length-1) {
            sCount[s[i] - 'a']++
        }
        while(start+p.length < s.length) {
            // 检查
            if (pCount.contentEquals(sCount)) {
                result.add(start)
            }
            // 滑动窗口
            sCount[s[start]-'a']--
            sCount[s[start+p.length]-'a']++
            start++
        }

        // 最后的窗口
        if (pCount.contentEquals(sCount)) {
            result.add(start)
        }

        return result
    }
}
// 力扣438思路 滑动窗口 维护哈希表 存储字母的数量，每次滑动减去上一个加上下一个，然后对比和p串的哈希表