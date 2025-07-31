class Solution {
    // 思路 找重叠区间
    fun findMinArrowShots(points: Array<IntArray>): Int {
        var count = 1
        val sortedList = points.sortedBy { it[1] }
        var currentPlace = sortedList[0][1]

        for (i in 1 until sortedList.size) {
            // 如果当前气球的起点在当前箭的右边，说明打不到，需要新箭
            if (sortedList[i][0] > currentPlace) {
                count++
                currentPlace = sortedList[i][1] // 新箭打在当前气球的右边界
            }
        }
        
        return count
    }
}