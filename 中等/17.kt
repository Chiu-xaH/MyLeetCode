class Solution {
    private val map = mapOf(
        '2' to listOf('a','b','c'),
        '3' to listOf('d','e','f'),
        '4' to listOf('g','h','i'),
        '5' to listOf('j','k','l'),
        '6' to listOf('m','n','o'),
        '7' to listOf('p','q','r','s'),
        '8' to listOf('t','u','v'),
        '9' to listOf('w','x','y','z')
    )
    // 递归
    fun letterCombinations(digits: String): List<String> {
        val result = mutableListOf<String>()
        if (digits.isEmpty()) return result

        fun backtrack(index: Int, current: String) {
            if(index == digits.length) {
                result.add(current)
                return
            }
            // 可能的字母
            val letters = map[digits[index]] ?: return
            letters.forEach { ch ->
                backtrack(index + 1,current + ch)
            }
        }
        // 开始
        backtrack(0, "")
        return result
    }
}
