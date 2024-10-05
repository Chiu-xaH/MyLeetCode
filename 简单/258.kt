class Solution {
    fun addDigits(num: Int): Int {
        var n = num;
        while(n >= 10) {
            var sum = 0;
            val str = n.toString();
            str.forEach { ch->
                sum += (ch - '0');
            }
            n = sum.toInt();
        }
        return n;
    }
}