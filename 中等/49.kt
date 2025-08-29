class Solution {
    fun groupAnagrams(strs: Array<String>): List<List<String>> {
        val pairList = mutableListOf<Pair<String, Map<Char, Int>>>()

        for (str in strs) {
            val letterMap = mutableMapOf<Char, Int>()
            for (ch in str) {
                letterMap[ch] = (letterMap[ch] ?: 0) + 1
            }
            pairList.add(Pair(str, letterMap))
        }

        val result = mutableMapOf<Map<Char, Int>, MutableList<String>>()

        for (pair in pairList) {
            val str = pair.first
            val letterMap = pair.second

            if (!result.containsKey(letterMap)) {
                result[letterMap] = mutableListOf()
            }

            result[letterMap]!!.add(str)
            // result.computeIfAbsent(count) { mutableListOf() }.add(str)
        }

        return result.values.toList()
    }
}

// 思路 每个单词生成哈希表统计字母数量 将所有哈希表遍历，一样的就归纳为一类