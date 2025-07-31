class Solution {
    fun countBits(n: Int): IntArray {
        val res = IntArray(n + 1)
        for (i in 0..n) {
            res[i] = countOnes(i)
        }
        return res
    }

    private fun countOnes(num: Int): Int {
        var count = 0
        var x = num
        while (x != 0) {
            if (x and 1 == 1) count++
            x = x shr 1
        }
        return count
    }
}