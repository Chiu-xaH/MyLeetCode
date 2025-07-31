class Solution {
    fun maxOperations(nums: IntArray, k: Int): Int {
        val map = mutableMapOf<Int, Int>()
        var count = 0
        nums.forEach { item ->
            val target = k - item
            // 是否存在可以配对的数
            if (map.getOrDefault(target, 0) > 0) {
                count++
                map[target] = map[target]!! - 1
            } else {
                map[item] = map.getOrDefault(item, 0) + 1
            }
        }

        return count
    }
}