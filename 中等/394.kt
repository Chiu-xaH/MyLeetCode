class Solution {
    private var i = 0
    
    fun decodeString(s: String): String {
        var str = ""
        var num = 0

        while (i < s.length) {
            val ch = s[i]
            when {
                ch.isDigit() -> {
                    // 多位数字
                    num = num * 10 + (ch - '0')
                }
                ch == '[' -> {
                    i++
                    // 递归
                    val sub = decodeString(s) 
                    repeat(num) { 
                        str += sub
                    }
                    // 复位
                    num = 0
                }
                ch == ']' -> {
                    // 结束
                    return str 
                }
                else -> {
                    str += ch
                }
            }
            i++
        }
        return str
    }
}