class Solution {
    fun addStrings(num1: String, num2: String): String {
        var ptr1 = num1.length-1
        var ptr2 = num2.length-1
        var carry = 0
        val sb = StringBuilder()
        while(ptr1 >= 0 && ptr2 >= 0) {
            val n1 = num1[ptr1] - '0'
            val n2 = num2[ptr2] - '0'
            val total = n1 + n2 + carry
            val result = total % 10
            carry = total / 10
            sb.append('0' + result)
            ptr1--
            ptr2--
        }
        while(ptr1 >= 0) {
            val n1 = num1[ptr1] - '0'
            val total = n1 + carry
            val result = total % 10
            carry = total / 10
            sb.append('0' + result)
            ptr1--
        }
        while(ptr2 >= 0) {
            val n2 = num2[ptr2] - '0'
            val total = n2 + carry
            val result = total % 10
            carry = total / 10
            sb.append('0' + result)
            ptr2--
        }
        if(carry > 0) {
            sb.append('0' + carry)
        }
        return sb.reversed().toString()
    }
}