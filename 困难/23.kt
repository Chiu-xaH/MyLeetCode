class Solution {
    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        val pirorQueue = PriorityQueue<ListNode>(compareBy { it.`val`})
        // 思路 优先队列先add入每个链表的表头 然后弹出并组成新的链表，直到队列为空后
        for(node in lists) {
            node?.let { pirorQueue.add(it) }
        }
        val dummy = ListNode(0)
        var list = dummy
        while(pirorQueue.isNotEmpty()) {
            val head = pirorQueue.poll()
            list.next = head
            list = list.next
            
            val next = head.next
            // 压入
            next?.let { pirorQueue.add(it) }
        }
        return dummy.next
    }
}