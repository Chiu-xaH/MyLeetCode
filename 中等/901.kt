class StockSpanner() {
    private data class Bean(val price : Int,val count : Int)
    private val stack = mutableListOf<Bean>()

    private fun pop() : Bean? {
        if(stack.isEmpty()) {
            return null
        }
        return stack.removeAt(stack.size - 1)
    }

    private fun getTop() : Bean? {
        if(stack.isEmpty()) {
            return null
        }
        return stack[stack.size - 1]
    }

    private fun push(value : Bean) = stack.add(value)

    fun next(price: Int): Int {
        var i = 1
        while (stack.isNotEmpty() && getTop()?.price ?: 0 <= price) {
            i += pop()?.count ?: 0
        }
        push(Bean(price,i))
        return i
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = StockSpanner()
 * var param_1 = obj.next(price)
 */