class MyQueue {
    private val inStack = mutableListOf<Int>()  // 入队栈
    private val outStack = mutableListOf<Int>() // 出队栈

    fun push(x: Int) {
        inStack.add(x)
    }

    fun pop(): Int {
        if (outStack.isEmpty()) {
            while (inStack.isNotEmpty()) {
                outStack.add(inStack.removeAt(inStack.size - 1))
            }
        }
        // 栈顶 原栈底
        return outStack.removeAt(outStack.size - 1)
    }

    fun peek(): Int {
        if (outStack.isEmpty()) {
            while (inStack.isNotEmpty()) {
                outStack.add(inStack.removeAt(inStack.size - 1))
            }
        }
        return outStack[outStack.size - 1]
    }

    fun empty(): Boolean {
        return inStack.isEmpty() && outStack.isEmpty()
    }
}