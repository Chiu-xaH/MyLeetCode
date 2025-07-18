class Solution {
    fun <T> haveDistinct(list : List<T>) : Boolean = list.toSet().size == list.size
    fun uniqueOccurrences(arr: IntArray): Boolean {
        val map = mutableMapOf<Int, Int>()
        arr.forEach { item ->
            map[item] = 0
        }
        arr.forEach { item ->
            map[item] = map[item]!! + 1
        }
        val list = map.entries.map { it.value }
        return haveDistinct(list)
    }
}