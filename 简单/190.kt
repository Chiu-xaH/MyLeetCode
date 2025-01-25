class Solution {
    fun reverseBits(n: Int): Int {
        var result = 0
        var num = n
        for (i in 0 until 32) {
            result = result shl 1 // 左移一位
            result = result or (num and 1) // 取num的最低位并将其添加到result
            num = num shr 1 // 右移num，丢弃最低位
        }
        return result
    }
}
