class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        var ptr = 0
        val end = strs.map { it.length }.min()
        while(ptr < end) {
            // 判断是否相同
            var same = true
            var pre = strs[0][ptr]
            for(i in 1 until strs.size) {
                if(strs[i][ptr] != pre) {
                    same = false
                    break
                }
            }
            if(same) {
                ptr++
            } else {
                break
            }
        }
        return strs[0].substring(0,ptr)
    }
}