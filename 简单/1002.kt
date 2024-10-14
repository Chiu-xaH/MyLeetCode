//思路1：如果将其排序后，可以类似链表集合算法那样，但是排序需要时间复杂度多
//思路2：哈希表
class Solution {
    fun commonChars(words: Array<String>): List<String> {
        val minFreq = IntArray(26) { Int.MAX_VALUE }
        for(word in words) {
            val freq = IntArray(26) // 用于当前单词的字符频率统计
            word.forEach { ch ->
                freq[ch - 'a']++ // 统计每个字符的频率
            }
            // 更新全局最小频率
            for(i in 0 until 26) {
                minFreq[i] = minOf(minFreq[i], freq[i])
            }
        }
        val result = mutableListOf<String>()
        for (i in 0 until 26) {
            repeat(minFreq[i]) { // 将字符加入结果列表
                result.add(('a' + i).toString())
            }
        }
        return result
    }
}