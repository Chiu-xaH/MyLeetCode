class Solution {
    private val stack = mutableListOf<Int>()
    private fun getTop() : Int? = 
        if(stack.isEmpty()) {
            null
        } else {
            stack[stack.size-1]
        }
    private fun pop() : Int? = 
        if(stack.isEmpty()) {
            null
        } else {
            stack.removeAt(stack.size-1)
        }
    private fun push(e : Int) = stack.add(e)

    fun largestRectangleArea(heights: IntArray): Int {
        var ptr = 0
        var maxArea = 0
        val newHeights = IntArray(heights.size + 2)
        for (i in heights.indices) {
            newHeights[i + 1] = heights[i]
        }
        while(ptr < newHeights.size) {
            val top = getTop()
            val cur = newHeights[ptr]
            if(top == null || cur >= newHeights[top]) {
                push(ptr)
                ptr++
            } else {
                val height = newHeights[pop()!!]
                val left = getTop() ?: -1
                val width = ptr - left - 1
                maxArea = maxOf(maxArea, height * width)
            }
        }
        return maxArea
    }
}