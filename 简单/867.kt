class Solution {
    fun transpose(matrix: Array<IntArray>): Array<IntArray> {
        val columnSize = matrix.size
        val rowSize = matrix[0].size
        
        val tMatrix = Array(rowSize) { IntArray(columnSize) }
        
        for(i in matrix.indices) {
            for(j in 0 until matrix[i].size) {
                tMatrix[j][i] = matrix[i][j]
            }
        }
        return tMatrix
    }
}