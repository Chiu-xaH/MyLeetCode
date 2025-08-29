class Solution {
    fun merge(intervals: Array<IntArray>): Array<IntArray> {
        // 以起点排序
        val sorted = intervals.sortedBy { it[0] }
        // 1,3 2,6 4,5 12,18
        val result = mutableListOf<IntArray>()
        for (item in sorted) {
            val left = item[0]
            val right = item[1]
            // 结果为空 直接加入
            // 当前区间与上一个区间不重叠，直接加入
            if (result.isEmpty() || result.last()[1] < left) {
                result.add(intArrayOf(left, right))
            } else {
                // 有重叠，合并区间
                result.last()[1] = maxOf(result.last()[1], right)
            }
        }

        return result.toTypedArray()
    }
}