class LRUCache(private val capacity: Int) {
    private class ListNode(val key : Int,var data : Int) {
        var prev : ListNode? = null // 双链表
        var next : ListNode? = null
    }
    private val head = ListNode(0,0) // 头结点
    private val tail = ListNode(0,0) // 尾结点
    private val map = mutableMapOf<Int,ListNode>()

    init {
        head.next = tail
        tail.prev = head
    }

    fun get(key: Int): Int {
        if(map.containsKey(key)) {
            val node = map[key]!!
            // 放在最前面
            moveToHead(node)
            // 返回值
            return node.data
        } else {
            return -1
        }
    }

    private fun getNode(node : ListNode) {
        // 取出
        node.prev!!.next = node.next
        node.next!!.prev = node.prev
    }
    private fun addToHhead(node : ListNode) {
        // 接入头
        head.next!!.prev = node
        node.next = head.next
        node.prev = head
        head.next = node
    }
    private fun moveToHead(node : ListNode) {
        getNode(node)
        addToHhead(node)
    }

    fun put(key: Int, value: Int) {
        if(map.containsKey(key)) {
            // 更新
            val node = map[key]!!
            node.data = value
            // 移动到头部
            moveToHead(node)
        } else {
            // 插入
            // 检查数量超出则逐出最后结点
            if(map.size + 1 > capacity) {
                val lastNode = tail.prev!!
                // 哈希表中删掉
                map.remove(lastNode.key)
                // 链表中删掉
                tail.prev = lastNode.prev
                tail.prev!!.next = tail
            }
            val node = ListNode(key,value)
            // 插入到哈希表
            map[key] = node
            // 放在最前面
            addToHhead(node)
        }
    }
}
