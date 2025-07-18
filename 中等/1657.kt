class Solution {
    fun closeStrings(word1: String, word2: String): Boolean {
        if (word1.length != word2.length) return false

        val map1 = mutableMapOf<Char,Int>()
        val map2 = mutableMapOf<Char,Int>()
        word1.forEach { item ->
            map1[item] = map1.getOrDefault(item, 0) + 1
        }
        word2.forEach { item ->
            map2[item] = map2.getOrDefault(item, 0) + 1
        }
        if (map1.keys != map2.keys) return false

        val list1 = map1.values.sorted()
        val list2 = map2.values.sorted()
        return list1 == list2
    }
}