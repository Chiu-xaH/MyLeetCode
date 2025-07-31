class Solution {
    fun reverseWords(s: String): String {
        val sTrim = s.trim()
        var left = sTrim.length-1
        var right = sTrim.length-1
        val sb = StringBuilder()
        while(left >= 0) {
            // 找到开头
            while (left >= 0 && sTrim[left] != ' ') {
                left--
            }
            // 拼接
            if (sb.isNotEmpty()) sb.append(' ')
            sb.append(sTrim.substring(left + 1, right + 1))

            // 跳过空格
            while (left >= 0 && sTrim[left] == ' ') {
                left--
            }
            right = left
        }
        return sb.toString()
    }
}