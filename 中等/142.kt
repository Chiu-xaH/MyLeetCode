class Solution {
    fun detectCycle(head: ListNode?): ListNode? {
        val map = mutableMapOf<ListNode,Int>()
        var linkList = head
        while(linkList != null) {
            if(map.containsKey(linkList)) {
                return linkList
            } else {
                map[linkList] = 1
            }
            linkList = linkList.next
        }
        // 无环
        return null
    }
}

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class Solution {
    fun detectCycle(head: ListNode?): ListNode? {
        var fast : ListNode? = head
        var slow : ListNode? = head
        while (fast?.next != null) {
            slow = slow?.next
            fast = fast.next?.next
            if (slow == fast) {
                // 找环的入口
                var start = head
                while (start != slow) {
                    start = start?.next
                    slow = slow?.next
                }
                return start
            }
        }
        return null
    }
}