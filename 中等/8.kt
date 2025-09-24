class Solution {
    fun myAtoi(s: String): Int {
        if (s.isEmpty()) return 0
        // 前导空格
        var ptr = 0
        while(ptr < s.length && s[ptr] == ' ') {
            ptr++
        }
        val str = s.substring(ptr,s.length)
        // 正负号
        if (str.isEmpty()) return 0
        val flag = when(str[0]) {
            '-' -> {
                ptr = 1
                false
            }
            '+' -> {
                ptr = 1
                true
            }
            in '0'..'9' -> {
                ptr = 0
                true
            }
            else -> {
                return 0
            }
        }
        // 前导0
        while(ptr < str.length && str[ptr] == '0') {
            ptr++
        }
        // 寻找末尾（第一次非数字字符出现的位置）
        var end = ptr
        while(end < str.length && str[end] in '0'..'9') {
            end++
        }
        var sum = 0
        // 转换
        while(ptr < end) {
            // 乘数
            // 溢出检查
            val digit = str[ptr] - '0'
            if (sum > (Int.MAX_VALUE - digit) / 10) {
                return if (flag) Int.MAX_VALUE else Int.MIN_VALUE
            }
            sum = sum * 10 + digit
            // val f = Math.pow(10.0, (end - ptr).toDouble())
            // sum += f*(str[ptr]-'0')
            ptr++
        }
        return if(flag) sum else -sum
    }
}