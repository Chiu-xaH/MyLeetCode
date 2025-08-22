class Solution {
    private var stack = mutableListOf<Char>()
    private fun pop() : Char? {
        if(stack.isEmpty()) {
            return null
        }
        return stack.removeAt(stack.size-1)
    }
    private fun push(ch : Char) {
        stack.add(ch)
    }
    private fun getTop() : Char? {
        if(stack.isEmpty()) {
            return null
        }
        return stack[stack.size-1]
    }
    private fun findFirst(target : Char) : Int? {
        if(stack.isEmpty()) {
            return null
        }
        for(i in stack.size - 1 downTo 0)  {
            val ch = stack[i]
            if(ch == target) {
                return i
            }
        }
        return null
    }
    private fun popForm(target : Int)  {
        if(stack.isEmpty()) {
            return
        }
        if(target > stack.size-1) {
            return
        }
        while (stack.size - 1 >= target) {
            val e = pop()
        }
    }
    fun isValid(s: String): Boolean {
        s.forEach { ch ->
            if(ch == '(' || ch == '[' || ch == '{') {
                push(ch)
            } else {
                val top = getTop() ?: return false
                val j = if(ch == ')') '('
                else if(ch == ']') '['
                else '{'
                if(j != top) {
                    return false
                } else {
                    pop()
                }
            }
            // println(stack.toString())
        }
        return stack.isEmpty()
    }
}