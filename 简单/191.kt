class Solution {
    fun toBinary(n: Int): String {
        if (n == 0) return "0"
        var num = n
        var str = ""
        while(num > 0) {
            var ch = (num % 2).toString()
            str += ch
            num /= 2
        }
        return str
    }
    fun hammingWeight(n: Int): Int {
        val bin = toBinary(n)
        var count = 0
        bin.forEach { ch ->
            if(ch == '1') {
                count++
            }
        }
        return count
    }
}