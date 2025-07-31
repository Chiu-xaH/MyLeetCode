class Solution {
    fun eraseOverlapIntervals(intervals: Array<IntArray>): Int {
        val sorted = intervals.sortedBy { it[0] }
        var count = 0
        var first = sorted[0]
        for(i in 1 until sorted.size) {
            val second = sorted[i]
            if(second[0] >= first[1]) {
                // 无重叠
                first = second
            } else {
               // 有重叠
               count++
               if(second[1] < first[1]) {
                    first = second
               }
            }
        }
        return count
    }
}


