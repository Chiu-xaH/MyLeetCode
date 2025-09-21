class Solution {
    private val result = mutableListOf<List<String>>()

    // 能否放置
    private fun can(row : Int,col : Int,board : IntArray) : Boolean {
        for (i in 0 until row) {
            // 例如 (0,2)与(1,1),(0-1)==(2-1) 所以位于对角线
            if (board[i] == col || abs(row - i) == abs(board[i] - col)) {
                return false
            }
        }
        return true
    }

    private fun createBoard(board : IntArray,n : Int) {
        val solution = List(n) { r ->
            CharArray(n) { c -> 
                if (board[r] == c) 'Q' 
                else '.' 
            }
            .concatToString()
        }
        result.add(solution)
    }
    
    private fun solve(row : Int,n : Int,board : IntArray) {
        if(row == n) {
            // 构造棋盘
            createBoard(board,n)
            return
        }
        for(col in 0 until n) {
            if(can(row,col,board)) {
                board[row] = col
                solve(row+1,n,board)
            }
        }
    }

    fun solveNQueens(n: Int): List<List<String>> {
        // 第i行皇后所在的列
        val board = IntArray(n) { -1 }
        solve(0,n,board)
        return result
    }
}