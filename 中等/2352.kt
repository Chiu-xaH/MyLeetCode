class Solution {
    fun equalPairs(grid: Array<IntArray>): Int {
        val map = mutableMapOf<String,Int>()
        // 行
        for (i in 0 until grid.size) {
            val row = grid[i].joinToString(",")
            map[row] = map.getOrDefault(row, 0) + 1
        }
        var count = 0
        // 列
        for (j in 0 until grid.size) {
            val colBuilder = StringBuilder()
            for (i in 0 until grid.size) {
                colBuilder.append(grid[i][j]).append(",")
            }
            val col = colBuilder.toString().dropLast(1)
            count += map.getOrDefault(col, 0)
        }
        // 找出为value大于1的数量
        return count
    }
}