class Solution {
    fun restoreIpAddresses(s: String): List<String> {
        val result = mutableListOf<String>()
        val sb = StringBuilder()
        fun back(start : Int,dot : Int) {
            if(dot == 4 && start == s.length) {
                result.add(sb.toString())
                return
            }
            // 最多三位数
            for (len in 1..3) {
                // 超出长度
                if (start + len > s.length) {
                    break
                }
                val part = s.substring(start, start + len)
                // 前导0
                if (part.length > 1 && part.startsWith("0")) {
                    break
                }
                // 大于255
                val n = part.toIntOrNull()
                if (n == null || n > 255) {
                    break
                }

                val before = sb.length
                if (sb.isNotEmpty()) {
                    sb.append('.')
                } 
                sb.append(part)
                back(start + len, dot + 1)
                // 撤销
                sb.setLength(before) 
            }            
        }
        back(0,0)
        return result
    }
}