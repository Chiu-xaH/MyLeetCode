class Solution {
    fun findDifference(nums1: IntArray, nums2: IntArray): List<List<Int>> {
        val map = mutableMapOf<Int, Int>()

        // 去重后再处理
        nums1.toSet().forEach { item ->
            map[item] = 0
        }
        nums2.toSet().forEach { item ->
            map[item] = map.getOrDefault(item, 0)
        }

        nums1.toSet().forEach { item ->
            map[item] = map.getValue(item) + 1
        }
        nums2.toSet().forEach { item ->
            map[item] = map.getValue(item) + 2
        }

        return listOf(
            map.filter { it.value == 1 }.keys.toList(),
            map.filter { it.value == 2 }.keys.toList()
        )
    }
}
