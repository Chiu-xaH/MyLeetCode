class Solution {
    fun isPalindrome(s: String): Boolean {
        val filteredStr = s.lowercase(Locale.getDefault())
        .filter { it.isLetterOrDigit() }

    // 检查过滤后的字符串是否为回文
    return filteredStr == filteredStr.reversed()
    }
}