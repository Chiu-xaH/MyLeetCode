class Solution {
    private val result = mutableListOf<String>()
    fun generateParenthesis(n: Int): List<String> {
        if(n <= 0) {
            return result
        }
        r("",n,n)
        return result
    }
    // 可用数量
    fun r(str: String,left: Int,right: Int) {
        if(left == 0 && right == 0) {
            result.add(str)
            return
        }
        if(left > right) {
            // 右括号更多 回溯
            return
        }
        if(left >= 1) {
            r(str + "(",left-1,right)
        }
        if(right >= 1) {
            r(str + ")",left,right-1)
        }
    }
}